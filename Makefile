# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 15:25:21 by tlenglin          #+#    #+#              #
#    Updated: 2017/02/09 15:49:50 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC1 = main_checker.c ft_free.c ft_instructions.c ft_instructions_tools.c ft_execution.c ft_execution2.c ft_execution3.c ft_execution4.c ft_check.c ft_optimization.c ft_optimization2.c ft_read_arg.c
SRC2 = main_push_swap.c ft_free.c ft_small_algo.c ft_read_arg.c ft_split_a.c ft_split_b.c ft_parsing.c ft_parsing2.c ft_parsing3.c ft_algo_tools.c ft_algorithm3.c ft_optimization.c ft_optimization2.c ft_algorithm1.c ft_instructions.c ft_instructions_tools.c ft_execution.c ft_execution2.c ft_execution3.c ft_execution4.c ft_check.c ft_get_value.c ft_loop.c ft_pull_up.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

FLAGS = -Wall -Wextra -Werror

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
