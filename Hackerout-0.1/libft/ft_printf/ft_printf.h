/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:24:36 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/09/25 14:32:51 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <aio.h>
# include <limits.h>

# define FD 1
# define ULL_MAX ULLONG_MAX

int		ft_printf(char const *str, ...);
ssize_t	ft_write_str(char *str);
ssize_t	ft_write_int(int n);
ssize_t	ft_write_char(char c);
ssize_t	ft_write_int_base(int num, int bsize, char *base, ssize_t *digits);
ssize_t	ft_write_hex_low(unsigned int n);
ssize_t	ft_write_hex_upp(unsigned int n);
ssize_t	ft_write_ptr(void *ptr);
ssize_t	ft_wub(unsigned long long c, unsigned long long s, char *b, ssize_t *d);
ssize_t	ft_write_dec(int n);
ssize_t	ft_write_uns(unsigned int n);

#endif
