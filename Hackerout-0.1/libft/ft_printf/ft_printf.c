/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:01:04 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:38:54 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_input_check(const char *str, size_t *i, va_list args)
{
	char	c;

	c = str[*i + 1];
	if (c == '%')
		return (ft_write_char('%'));
	if (c == 'c')
		return (ft_write_char(va_arg(args, int)));
	if (c == 's')
		return (ft_write_str(va_arg(args, char *)));
	if (c == 'p')
		return (ft_write_ptr(va_arg(args, void *)));
	if (c == 'd')
		return (ft_write_dec(va_arg(args, int)));
	if (c == 'i')
		return (ft_write_int(va_arg(args, int)));
	if (c == 'u')
		return (ft_write_uns(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_write_hex_low(va_arg(args, int)));
	if (c == 'X')
		return (ft_write_hex_upp(va_arg(args, int)));
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list		args;
	int			prints;
	size_t		i;
	ssize_t		res;

	i = 0;
	prints = 0;
	va_start(args, str);
	while (str[i])
	{
		res = 0;
		if (str[i] != '%')
			res = ft_write_char(str[i]);
		else
		{
			res = ft_input_check(str, &i, args);
			i++;
		}
		i++;
		if (res < 0)
			return (-1);
		prints = prints + res;
	}
	va_end(args);
	return (prints);
}
