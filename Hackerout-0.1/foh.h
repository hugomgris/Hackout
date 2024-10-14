/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 08:43:59 by hmunoz-g          #+#    #+#             */
/*   Updated: 2024/10/11 11:34:53 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOH_H
# define FOH_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <time.h>
# include <fcntl.h>

//BUILDER functions
char	**builder_init(int diff, int delay, char **answers);
char	**make_tab(int diff, char **answers);
char	**prebuild(char **tab, int row_l, int rows, int diff);
char	*fill_row(char *row, int row_l, int diff);
int	get_random_symbol();
int	get_random_number(int span);
int	dif_sizes(int *word_l, int *row_l, int *rows, int diff);

//PRINTER functions
void	print_init(char *tab, int delay);
void	print_seq(const char *str, int delay);
void	reset_color();
void	set_color(const char *color);

//GETTER functions
char    **getter_init(int diff);
char	*get_password(char **answers);

//INJECTOR functions
char	**injector_init(char **tab, char **answers, int diff);
char	**pre_inject(char **tab, char **answers, int minl, int maxl, int minr, int maxr, int diff);
char	**inject(char **tab, int row_to_inject, int injector, char **answers, int words);
int	random_injector(int minl, int maxl, int minr, int maxr);
int	valid_pos(char **tab, int row_to_inject, int injector, int diff);
int	is_gib(char c);

//MANAGER functions
void	manager_init(char **tab, char *password, int delay, int diff);
void	input_manager(char **tab, char *password, int delau, int diff, int tries);
void	retry(int tires, int delay);
void	success(int delay);
void	failure(int delay);
void	input_setup(int delay);
int	check_similarity(char *input, char *answer);
void	process_similarity(char *similarity, int delay);

#endif
