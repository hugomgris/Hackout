/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:53:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 13:51:06 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_wrin(int num, int bsize, char *base, ssize_t *digits)
{
	size_t	pos;
	ssize_t	res;

	if (num <= -bsize)
	{
		if (ft_wrin(num / bsize, bsize, base, digits) == -1)
			return (-1);
	}
	pos = num % bsize;
	res = write(FD, &base[-pos], 1);
	if (res == -1)
		return (-1);
	else if (res == 1)
	{
		*digits = *digits + 1;
		res = *digits;
	}
	return (res);
}

static ssize_t	ft_wrip(int num, int bsize, char *base, ssize_t *digits)
{
	size_t	pos;
	ssize_t	res;

	if (num >= bsize)
	{
		if (ft_wrip(num / bsize, bsize, base, digits) == -1)
			return (-1);
	}
	pos = num % bsize;
	res = write(FD, &base[pos], 1);
	if (res == -1)
		return (-1);
	else if (res == 1)
	{
		*digits = *digits + 1;
		res = *digits;
	}
	return (res);
}

ssize_t	ft_write_int_base(int num, int bsize, char *base, ssize_t *digits)
{
	ssize_t	res;

	if ((num >= 0) && (num <= INT_MAX))
		res = ft_wrip(num, bsize, base, digits);
	else if (num >= INT_MIN)
	{
		if (write(FD, "-", 1) != 1)
			return (-1);
		*digits = *digits + 1;
		res = ft_wrin(num, bsize, base, digits);
	}
	else
		return (-1);
	if (res > 0)
		res = *digits;
	return (res);
}
