/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:25:12 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 11:51:22 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_write_str(char *str)
{
	ssize_t	i;
	ssize_t	res;

	i = 0;
	if (!str)
		return (ft_write_str("(null)"));
	while (str[i])
	{
		res = write(FD, &str[i], 1);
		if (res == -1)
			return (res);
		i++;
	}
	return (i);
}
