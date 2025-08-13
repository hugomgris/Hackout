/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:09:44 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/14 09:28:06 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

char	*get_password(char **answers)
{
	int	i = get_random_number(15);
	return (answers[i]);
}

char	**getter_init(int diff)
{
	int 	fd = 0; 
	int		level_size = 0;
	char	**answers;

	if (diff == 1)
		fd = open("levels/level1.txt", O_RDONLY);
	else if (diff == 2)
		fd = open("levels/level2.txt", O_RDONLY);
	else
		fd = open("levels/level3.txt", O_RDONLY);
	
	if (fd == -1)
	{
		perror("Error opening file");
		return (NULL);
	}
	answers = (char **)malloc(sizeof(char *) * 16);
	if (answers == NULL)
	{
		close(fd);
		return (NULL);
	}
	int i = get_random_number(115);
	if (i >= 15)
		i -= 15;
	while (i >= 0)
	{
		answers[0] = get_next_line(fd);
		i--;
	}
	while(i < 14)
	{
		answers[level_size] = get_next_line(fd);
		if (answers[level_size] == NULL)
			break;
		level_size++;
		i++;
	}
	answers[level_size] = NULL;
	close(fd);
	return (answers);
}
