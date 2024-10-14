/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_upp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:42:59 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 13:58:39 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_hex_upp(unsigned int n)
{
	ssize_t	digits;

	digits = 0;
	return (ft_wub(n, 16, "0123456789ABCDEF", &digits));
}
