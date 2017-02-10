/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:17:05 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:17:34 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execution_rb(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	if (stack->length_b <= 1)
		return (1);
	first = stack->stack_b[stack->length - stack->length_b];
	while (i < (stack->length_b - 1))
	{
		stack->stack_b[stack->length - stack->length_b + i] =
		stack->stack_b[stack->length - stack->length_b + 1 + i];
		i++;
	}
	stack->stack_b[stack->length - 1] = first;
	ft_realloc_string(stack, 6);
	ft_realloc_string(stack, -1);
	return (1);
}

int	ft_execution_rra(t_stack *stack)
{
	int	i;
	int	last;

	i = 0;
	if (stack->length_a <= 1)
		return (1);
	last = stack->stack_a[stack->length - 1];
	while (i < (stack->length_a - 1))
	{
		stack->stack_a[stack->length - 1 - i] =
		stack->stack_a[stack->length - i - 2];
		i++;
	}
	stack->stack_a[stack->length - stack->length_a] = last;
	ft_realloc_string(stack, 7);
	ft_realloc_string(stack, -1);
	return (1);
}

int	ft_execution_rrb(t_stack *stack)
{
	int	i;
	int	last;

	i = 0;
	if (stack->length_b <= 1)
		return (1);
	last = stack->stack_b[stack->length - 1];
	while (i < (stack->length_b - 1))
	{
		stack->stack_b[stack->length - 1 - i] =
		stack->stack_b[stack->length - i - 2];
		i++;
	}
	stack->stack_b[stack->length - stack->length_b] = last;
	ft_realloc_string(stack, 8);
	ft_realloc_string(stack, -1);
	return (1);
}

int	ft_execution_ss(t_stack *stack)
{
	ft_execution_sa(stack);
	ft_execution_sb(stack);
	return (1);
}

int	ft_execution_rr(t_stack *stack)
{
	ft_execution_ra(stack);
	ft_execution_rb(stack);
	return (1);
}
