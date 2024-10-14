/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:21:57 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/14 15:44:47 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

int	check_similarity(char *input, char *answer)
{
	int	i = 0;
	int count = 0;

	while (input[i])
	{
		if (input[i] == answer[i])
			count++;
		i++;
	}
	return (count);
}

void retry (int tries, int delay)
{
	//int		similarity = 0;
	//int	i = 0;
	//similarity = check_similarity(input, answer);
	if (tries == 3)
		print_seq(">Attempts remaining: ▣ ▣ ▣ ", delay);
	else if (tries == 2)
		print_seq(">Attempts remaining: ▣ ▣  ", delay);
	else if (tries == 1)
		print_seq(">Attempts remaining: ▣   ", delay);
	else
		print_seq(">Attempts remaining:  ", delay);
	printf("\n");
}

void	success(int delay)
{
    printf("\n");
    print_seq("PASSWORD ACCEPTED. ACCESS GRANTED.", delay);
	printf("\n");
}

void	failure(int delay)
{
	printf("\n");
	print_seq("TOO MANY FAILED ATTEMPTS. INTRUDER DETECTED. SHUTTING DOWN.", delay);
	printf("\n");
}

void	process_similarity(char *similarity, int delay)
{
	char	*res = ft_strjoin(">similarity: ", similarity);
	if (res == NULL)
		return ;
	print_seq(res, delay);
}

void	input_manager(char **tab, char *password, int delay, int diff, int tries)
{
	char	*input;

	input = (char *)malloc(sizeof(char) * (4 + diff));
	if (input == NULL)
		return ;
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0;
	int	i = 0;
	while (input[i])
	{
		input[i] = ft_toupper(input[i]);
		i++;
	}
	if (!ft_strncmp(input, password, ft_strlen(input)))
	{
		success(delay);
	}
	else if (ft_strncmp(input, password, ft_strlen(input)) && tries)
	{
		print_seq(">Wrong password", delay);
		char *similarity = ft_itoa(check_similarity(input, password));
		process_similarity(similarity, delay);
		tries--;
		retry(tries, delay);
		input_manager(tab, password, delay, diff, tries);
	}
	else
		failure(delay);
}

void	manager_init(char **tab, char *password, int delay, int diff)
{
	int tries = 4;

	printf("\n");
	print_seq("Attempts remaining: ▣ ▣ ▣ ▣", delay);
	printf("\n");
	print_seq("Enter password:", delay);
	printf("\n");
	input_manager(tab, password, delay, diff, tries);
}
