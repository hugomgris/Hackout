/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foh_mockup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:56:15 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/11 11:11:10 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

void	set_color(const char *color)
{
	printf("%s", color);
}

void reset_color()
{
	printf("\033[0m");
}

void	print_noseq(const char *str)
{
	int i = 0;
	set_color("\033[1;32m");
	while(str[i])
	printf("%c", str[i]);
	reset_color();
}

void	print_seq(const char *str, int delay)
{
	int	i = 0;

	set_color("\033[1;32m");

	while (str[i])
	{
		printf("%c", str[i]);
		fflush(stdout);
		usleep(delay);
		i++;
	}

	reset_color();
	printf("\n");
}



void	print_init(char	*tab, int delay)
{
	print_seq(tab, delay);
}
