/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:21:38 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 21:50:46 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_stupid_function(t_stack *stack)
{
	ft_split_stack_b(stack, 12);
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	return (1);
}

int			ft_big_fucking_recursive(t_stack *stack, int loop)
{
	int j;

	if (loop == 1)
		ft_stupid_function(stack);
	else
	{
		ft_split_stack_b(stack, 6 * ft_power(loop));
		j = 0;
		while (j < 3 * ft_power(loop))
		{
			ft_execution_pb(stack);
			j++;
		}
		loop--;
		ft_big_fucking_recursive(stack, loop);
		ft_big_fucking_recursive(stack, loop);
	}
	return (1);
}

int			ft_last_sorting_ever(t_stack *stack)
{
	int max;

	max = 0;
	while (stack->length_b > 0)
	{
		max = ft_get_max(stack->stack_b, stack->length_b, stack->length);
		ft_pull_up_b(max, stack);
		ft_execution_pa(stack);
	}
	return (1);
}

int			ft_here_comes_the_split(t_stack *stack)
{
	int cut;
	int loop;
	int i;

	i = 1;
	if (stack->length_b <= 6)
	{
		ft_last_sorting_ever(stack);
		return (1);
	}
	cut = ft_first_split_b(stack);
	loop = ft_second_split_loop(stack, cut);
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	while (i < loop + 1)
	{
		ft_big_fucking_recursive(stack, i);
		i++;
	}
	ft_here_comes_the_split(stack);
	return (1);
}

int			ft_fat_algo(t_stack *stack)
{
	int loop;
	int cut;
	int i;

	i = 1;
	if (stack->length_a <= 6)
		return (ft_mini_algo(stack));
	cut = ft_first_split_a(stack);
	loop = ft_first_split_loop(stack) - 1;
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	while (i < loop + 1)
	{
		ft_big_fucking_recursive(stack, i);
		i++;
	}
	ft_here_comes_the_split(stack);
	return (0);
}
