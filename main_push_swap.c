/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:28:46 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 17:53:55 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char *result;

	result = NULL;
	if (argc == 1)
		return (0);
	ft_launch_algo(argc, argv, &result);
	if (!result)
	{
	
		return (0);
	}
	ft_print_instructions(result);
	free(result);

	return (0);
}

int	ft_launch_algo(int argc, char **argv, char **result)
{
	t_stack	stack;

	if (ft_read_arg(argc, argv, &stack) == 0)
		return (0);
	if (ft_check_stack_order(&stack) == 1 && (*result = ft_strnew(0)))
	{
		free(stack.stack_a);
		free(stack.stack_b);
		return (1);
	}
	if (stack.length_a < 5)
		ft_sorting_algo1_a(&stack);
	else if (stack.length_a == 5)
		ft_mini_algo(&stack);
	else
		ft_fat_algo(&stack);
	if (stack.instructions != NULL)
	{
		*result = ft_strdup(stack.instructions);
		free(stack.instructions);
	}
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}

int	ft_print_instructions(char *result)
{
	int i;

	i = 0;
	ft_optimize_instructions(&result);
	while (result[i])
	{
		if (result[i] == '1' || result[i] == '2' || result[i] == '3' ||
		result[i] == '4' || result[i] == '5' || result[i] == '6' ||
		result[i] == '7' || result[i] == '8' || result[i] == ',' ||
		result[i] == '.' || result[i] == ':')
			ft_print_instructions_bis(result[i]);
		else if (result[i] == '\n')
			ft_putchar('\n');
		i++;
	}
	return (0);
}

int	ft_print_instructions_bis(char c)
{
	if (c == '1')
		ft_putstr("sa");
	else if (c == '2')
		ft_putstr("sb");
	else if (c == '3')
		ft_putstr("pa");
	else if (c == '4')
		ft_putstr("pb");
	else if (c == '5')
		ft_putstr("ra");
	else if (c == '6')
		ft_putstr("rb");
	else if (c == '7')
		ft_putstr("rra");
	else if (c == '8')
		ft_putstr("rrb");
	else if (c == ',')
		ft_putstr("ss");
	else if (c == '.')
		ft_putstr("rr");
	else if (c == ':')
		ft_putstr("rrr");
	return (1);
}
