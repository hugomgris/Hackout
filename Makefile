# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 15:45:04 by hmunoz-g          #+#    #+#              #
#    Updated: 2025/08/13 17:14:35 by hmunoz-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-    COLOURS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

DEF_COLOR   = \033[0;39m
YELLOW      = \033[0;93m
CYAN        = \033[0;96m
GREEN       = \033[0;92m
BLUE        = \033[0;94m
RED         = \033[0;91m

# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME        := hackout

# -=-=-=-=-    FLAG -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CC          = cc
FLAGS       = -Wall -Werror -Wextra -g
DEPFLAGS    = -MMD -MP

# -=-=-=-=-    PATH -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

RM          = rm -fr
OBJ_DIR     = .obj
DEP_DIR     = .dep
LIBFT_DIR   = libft

# -=-=-=-=-    LIBRARIES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

LIBFT_A     = $(LIBFT_DIR)/libft.a

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC         := launcher.c \
				builder.c \
				printer.c \
				getter.c \
				injector.c \
				manager.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS        = $(addprefix $(DEP_DIR)/, $(SRC:.c=.d))

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: directories libft $(NAME)

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

-include $(DEPS)

libft:
	@echo "$(CYAN)Building libft...$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c 
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(FLAGS) $(DEPFLAGS) -I. -c $< -o $@ -MF $(DEP_DIR)/$*.d

$(NAME): $(OBJS) $(LIBFT_A) Makefile
	@echo "$(GREEN)Linking $(NAME)!$(DEF_COLOR)"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"
	@echo "$(CYAN)Ready to hack some terminals! Run './$(NAME) play' to start$(DEF_COLOR)"

# -=-=-=-=-    GAME TARGET -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

game: all
	@echo "$(BLUE)Starting Hackout...$(DEF_COLOR)"
	@./$(NAME) play

# -=-=-=-=-    CLEANUP TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

clean:
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)Cleaned object files and dependencies$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re directories libft game
