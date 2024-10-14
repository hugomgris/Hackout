# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:45:04 by hmunoz-g          #+#    #+#              #
#    Updated: 2024/09/25 14:34:25 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = foh.a

SRC = launcher.c \
	builder.c \
	printer.c \
	getter.c \
	injector.c \
	manager.c 

OBJ = $(SRC:.c=.o) $(LIBFT:.c=.o)

LIBFT = libft/ft_strlen.c \
	libft/ft_strncmp.c \
	libft/ft_strdup.c \
	libft/ft_strlcpy.c \
	libft/ft_strchr.c \
	libft/ft_substr.c \
	libft/ft_strjoin.c \
	libft/ft_free.c \
	libft/ft_toupper.c \
	libft/ft_itoa.c \
	libft/get_next_line.c
	
CC = cc -Wall -Werror -Wextra

%.o: %.c Makefile foh.h libft/libft.h
	$(CC) -I. -c $< -o $@

all: $(NAME)

game: $(OBJ) foh.h libft/libft.h
	ar rcs $(NAME) $(OBJ) $(LIBFT)
	$(CC) printer.c builder.c launcher.c injector.c manager.c foh.a && ./a.out play
	
$(NAME): $(OBJ) foh.h libft/libft.h
	ar rcs $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
