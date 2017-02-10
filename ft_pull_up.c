/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pull_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:32:56 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:33:22 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pull_up_b(int i, t_stack *stack)
{
	int	up;
	int	down;
	int	j;

	j = 0;
	up = i - (stack->length - stack->length_b);
	down = (stack->length - 1) - i + 1;
	if (up <= down)
	{
		while (j < up)
		{
			ft_execution_rb(stack);
			j++;
		}
	}
	else
	{
		while (j < down)
		{
			ft_execution_rrb(stack);
			j++;
		}
	}
	return (0);
}

int	ft_pull_up_a(int i, t_stack *stack)
{
	int	up;
	int	down;
	int	j;

	j = 0;
	up = i - (stack->length - stack->length_a);
	down = (stack->length - 1) - i + 1;
	if (up <= down)
	{
		while (j < up)
		{
			ft_execution_ra(stack);
			j++;
		}
	}
	else
	{
		while (j < down)
		{
			ft_execution_rra(stack);
			j++;
		}
	}
	return (0);
}

int	ft_pull_up_min_b(t_stack *stack)
{
	t_algo	algo;

	algo.i = stack->length - stack->length_b;
	algo.min = stack->stack_b[stack->length - stack->length_b];
	if (algo.i == (stack->length - 1))
		return (1);
	algo.i++;
	while (algo.i < (stack->length) && stack->stack_b[algo.i - 1] <
	stack->stack_b[algo.i])
		algo.i++;
	if (algo.i != (stack->length))
		ft_pull_up_b(algo.i, stack);
	return (0);
}

int	ft_pull_up_min_a(t_stack *stack)
{
	t_algo	algo;

	algo.i = stack->length - stack->length_a;
	algo.min = stack->stack_a[stack->length - stack->length_a];
	if (algo.i == (stack->length - 1))
		return (1);
	algo.i++;
	while (algo.i < (stack->length) && stack->stack_a[algo.i - 1] <
	stack->stack_a[algo.i])
		algo.i++;
	if (algo.i != (stack->length))
		ft_pull_up_a(algo.i, stack);
	return (0);
}
