/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:31:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:33:18 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_uns(unsigned int n)
{
	ssize_t	digits;

	digits = 0;
	return (ft_wub(n, 10, "0123456789", &digits));
}
