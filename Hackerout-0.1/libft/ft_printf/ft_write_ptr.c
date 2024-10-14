/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:14:53 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:23:47 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_ptr(void *ptr)
{
	ssize_t				digits;
	unsigned long long	conv;

	conv = (unsigned long long)ptr;
	if (conv == 0)
	{
		if (ft_write_str("(nil)") != 5)
			return (-1);
		else
			return (5);
	}
	if (ft_write_str("0x") != 2)
		return (-1);
	digits = 2;
	return (ft_wub(conv, 16, "0123456789abcdef", &digits));
}
