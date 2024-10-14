/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:28:38 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:30:19 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_dec(int n)
{
	ssize_t	digits;

	digits = 0;
	return (ft_write_int_base(n, 10, "0123456789", &digits));
}
