# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 15:25:21 by tlenglin          #+#    #+#              #
#    Updated: 2017/02/02 14:30:59 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC1 = main_checker.c ft_instructions.c ft_execution.c ft_check.c ft_optimization.c
SRC2 = main_push_swap.c ft_parsing.c ft_algo_tools.c ft_algorithm3.c ft_optimization.c ft_algorithm2.c ft_algorithm1.c ft_instructions.c ft_execution.c ft_check.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

CC = gcc

LIBFT_PATH = ./libft

all: $(NAME)

$(NAME): $(OBJ1) $(OBJ2)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ1) -L./libft -lft
	@$(CC) $(FLAGS) -o push_swap $(OBJ2) -L./libft -lft

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ1)
	@rm -rf $(OBJ2)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf push_swap
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
