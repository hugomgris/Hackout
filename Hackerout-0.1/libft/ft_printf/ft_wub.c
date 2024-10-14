/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:06:31 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:24:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_unsigned(unsigned long long conv,
		unsigned long long bsize, char *base, ssize_t *digits)
{
	size_t	pos;
	ssize_t	res;

	if (conv >= bsize)
	{
		if (ft_write_unsigned(conv / bsize, bsize, base, digits) == -1)
			return (-1);
	}
	pos = conv % bsize;
	if (write(FD, &base[pos], 1) != 1)
		return (-1);
	else
	{
		*digits = *digits + 1;
		res = *digits;
	}
	return (res);
}

ssize_t	ft_wub(unsigned long long c,
		unsigned long long s, char *b, ssize_t *d)
{
	ssize_t	res;

	if (c <= ULL_MAX)
		res = ft_write_unsigned(c, s, b, d);
	else
		return (-1);
	if (res > 0)
		res = *d;
	return (res);
}
