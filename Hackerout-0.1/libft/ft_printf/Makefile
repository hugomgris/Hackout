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

NAME = ft_printf.a

SRC = ft_printf.c \
	ft_write_char.c \
	ft_write_dec.c \
	ft_write_hex_low.c \
	ft_write_hex_upp.c \
	ft_write_int.c \
	ft_write_int_base.c \
	ft_write_ptr.c \
	ft_write_str.c \
	ft_write_uns.c \
	ft_wub.c 

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Werror -Wextra

%.o: %.c ft_printf.h libft/libft.h
	$(CC) -I. -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf.h Makefile
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
