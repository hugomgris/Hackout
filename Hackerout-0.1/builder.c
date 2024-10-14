/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 10:42:09 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/14 10:02:18 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

void	diff_sizes(int *word_l, int *row_l, int *rows, int diff)
{
	if (diff == 1)
	{
		*word_l = 4;
		*row_l = 45;
		*rows = 15;
	}
	else if(diff == 2)
	{
		*word_l = 5;
		*row_l = 47;
		*rows = 17;
	}
	else if(diff == 3)
	{
		*word_l = 6;
		*row_l = 49;
		*rows = 20;
	}
}

int	get_random_number(int span)
{
	int random_n = (rand() % span);
	return (random_n);
}

int	get_random_symbol()
{
	char	symbols[] = {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126};
	int		symbols_size = sizeof(symbols) / sizeof(symbols[0]);
	int random_index = rand() % symbols_size;
	int random_symbol = symbols[random_index];
	return (random_symbol);
}

char	*fill_row(char	*row, int row_l, int diff)
{
	int		i = 2;

	//rows of diff 1
	if (diff == 1)
	{
		row[0] = '0';
		row[1] = 'x';
		while (i <= 5 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 7 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i <= 19 && i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		while (i <= 24 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		row[25] = '0';
		row[26] = 'x';
		i += 2;
		while (i <= 30 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 32 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		row[i] = '\0';
	}
	
	//rows of diff 2
	if (diff == 2)
	{
		row[0] = '0';
		row[1] = 'x';
		while (i <= 5 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 7 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i <= 20 && i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		while (i <= 25 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		row[26] = '0';
		row[27] = 'x';
		i += 2;
		while (i <= 31 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 33 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		row[i] = '\0';
	}
	
	//rows of diff 3
	if (diff == 3)
	{
		row[0] = '0';
		row[1] = 'x';
		while (i <= 5 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 7 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i <= 21 && i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		while (i <= 26 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		row[27] = '0';
		row[28] = 'x';
		i += 2;
		while (i <= 32 && i < row_l)
		{
			row[i] = get_random_number(10) + '0';
			i++;
		}
		while (i <= 34 && i < row_l)
		{
			row[i] = ' ';
			i++;
		}
		while (i < row_l)
		{
			row[i] = get_random_symbol();
			i++;
		}
		row[i] = '\0';
	}
	return (row);
}

char **prebuild(char **tab, int row_l, int rows, int diff)
{
	int	i = 0;
	int row_count = 0;

	if (diff >=1 && diff <= 3)
	{
		while (i < rows)
		{
			tab[i] = (char *)malloc(sizeof(char) * (row_l + 1));
			if (tab[i] == NULL)
			{
				ft_free(tab);
				return (NULL);
			}
			tab[i] = fill_row(tab[i], row_l, diff);
			row_count++;
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}

char	**make_tab(int diff, char **answers)
{
	int		word_l;
	int 	row_l;
	int		rows;
	char	**tab;
	
	diff_sizes(&word_l, &row_l, &rows, diff);

	tab = (char **)malloc(sizeof(char *) * (rows + 1));
	if (tab == NULL)
		return (NULL);
	tab = prebuild(tab, row_l, rows, diff);
	tab = injector_init(tab, answers, diff);

	return (tab);
}

char	**builder_init(int diff, int delay, char **answers)
{
	char **tab = make_tab(diff, answers);
	int	i = 0;
	while (tab[i])
	{
		print_init(tab[i], delay);
		i++;
	}
	return(tab);
}
