/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:14:01 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/13 17:28:12 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "foh.h"

int	intro(int delay)
{
	int	diff = 0;
	char	input[50];

	system("clear");
	print_seq("WELCOME TO ROBCO INDUSTRIES(TM) TERMLINK(R) MATRIX\n", delay);
	print_seq("PLEASE SELECT ACCESS LEVEL (1-3)\n", delay);
	fgets(input, sizeof(input), stdin);
	diff = atoi(input);
	if (diff >= 1 && diff <= 3)
	{		
		system("clear");
		print_seq("ROBCO INDUSTRIES(TM) TERMLINK PROTOCOL\n", delay);
		print_seq("ERROR 404: PASSWORD NOT FOUND. PASSWORD REQUIRED\n", delay);
		printf("\n\n");
		return(diff);
	}
	else
	{
		print_seq("INVALID ACCESS LEVEL. THREAT DETECTED. SHUTTING DOWN\n", delay);
		exit(1);
	}
		
}

int	main(int argc, char **argv)
{
	srand(time(NULL));
	int	delay = 5000;
	int diff;
	
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "play", ft_strlen("play")) == 0) 
		{
			diff = intro(delay);
			char	**answers = getter_init(diff);
			char	**tab = builder_init(diff, delay, answers);
			char	*password = get_password(answers);
			manager_init(tab, password, delay, diff);
		}
		else
			print_seq("Bad init input. Please run program with argument 'play'", delay);
	}
	else 
		print_seq("Bad init input. Please run program with argument 'play'", delay);
}
