/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_low.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:39:10 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 13:58:53 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_hex_low(unsigned int n)
{
	ssize_t	digits;

	digits = 0;
	return (ft_wub(n, 16, "0123456789abcdef", &digits));
}
