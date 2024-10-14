/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:30:47 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/14 10:42:03 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

int	is_gib(char c)
{
	if ((c >= 33 && c <= 42) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

int	valid_pos(char **tab, int row_to_inject, int injector, int diff)
{
	if (diff == 1)
	{
		if (is_gib(tab[row_to_inject][injector]) && is_gib(tab[row_to_inject][injector + 1]) && is_gib(tab[row_to_inject][injector + 2]) && is_gib(tab[row_to_inject][injector + 3]) && is_gib(tab[row_to_inject][injector + 4]) && is_gib(tab[row_to_inject][injector - 1]))
		return (1);
	}
	else if (diff == 2)
	{
		if (is_gib(tab[row_to_inject][injector]) && is_gib(tab[row_to_inject][injector + 1]) && is_gib(tab[row_to_inject][injector + 2]) && is_gib(tab[row_to_inject][injector + 3]) && is_gib(tab[row_to_inject][injector + 4]) && is_gib(tab[row_to_inject][injector + 5]) && is_gib(tab[row_to_inject][injector - 1]))
		return (1);
	}
	else
	{
		if (is_gib(tab[row_to_inject][injector]) && is_gib(tab[row_to_inject][injector + 1]) && is_gib(tab[row_to_inject][injector + 2]) && is_gib(tab[row_to_inject][injector + 3]) && is_gib(tab[row_to_inject][injector + 4]) && is_gib(tab[row_to_inject][injector + 5]) && is_gib(tab[row_to_inject][injector + 6]) && is_gib(tab[row_to_inject][injector - 1]))
		return (1);
	}
	return (0);
}

int	random_injector(int	minl, int maxl, int minr, int maxr)
{
	int	injector;

	if(rand() % 2 == 0)
		injector = rand() % (maxl - minl + 1) + minl;
	else
		injector = rand() % (maxr - minr + 1) + minr;
	return (injector);
}

char	**inject(char **tab, int row_to_inject, int injector, char **answers, int words)
{
	int	i = 0;
	while (answers[words][i] && answers[words][i] != '\n')
	{
		tab[row_to_inject][injector + i] = answers[words][i];
		i++;
	}
	return (tab);
}

char	**pre_inject(char **tab, char **answers, int minl, int maxl, int minr, int maxr, int diff)
{
	int	words = 0;
	int rows = 0;

	while (answers[words])
		words++;
	while (tab[rows])
		rows++;
	rows--;
	words--;
	while (words >= 0)
	{
		int row_to_inject = rand() % (rows + 1);
		int	injector = random_injector(minl, maxl, minr, maxr);
		if(valid_pos(tab, row_to_inject, injector, diff))
		{
			inject(tab, row_to_inject, injector, answers, words);
			words--;
		}
	}
	return (tab);
}

char	**injector_init(char **tab, char **answers, int diff)
{
	if (diff == 1)
		tab = pre_inject(tab, answers, 8, 19, 33, 44, diff);
	else if (diff == 2)
		tab = pre_inject(tab, answers, 8, 20, 34, 46, diff);
	else
		tab = pre_inject(tab, answers, 8, 21, 35, 48, diff);
	return (tab);
}
