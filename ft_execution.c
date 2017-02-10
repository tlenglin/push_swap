/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:11:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:18:27 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execution_sa(t_stack *stack)
{
	int	tmp;

	if (stack->length_a >= 2)
	{
		tmp = stack->stack_a[stack->length - stack->length_a];
		stack->stack_a[stack->length - stack->length_a] =
		stack->stack_a[stack->length - stack->length_a + 1];
		stack->stack_a[stack->length - stack->length_a + 1] = tmp;
		ft_realloc_string(stack, 1);
		ft_realloc_string(stack, -1);
	}
	return (1);
}

int	ft_execution_sb(t_stack *stack)
{
	int	tmp;

	if (stack->length_b >= 2)
	{
		tmp = stack->stack_b[stack->length - stack->length_b];
		stack->stack_b[stack->length - stack->length_b] =
		stack->stack_b[stack->length - stack->length_b + 1];
		stack->stack_b[stack->length - stack->length_b + 1] = tmp;
		ft_realloc_string(stack, 2);
		ft_realloc_string(stack, -1);
	}
	return (1);
}

int	ft_execution_pa(t_stack *stack)
{
	if (stack->length_b >= 1)
	{
		stack->stack_a[stack->length - stack->length_a - 1] =
		stack->stack_b[stack->length - stack->length_b];
		stack->length_a++;
		stack->length_b--;
		ft_realloc_string(stack, 3);
		ft_realloc_string(stack, -1);
	}
	return (1);
}

int	ft_execution_pb(t_stack *stack)
{
	if (stack->length_a >= 1)
	{
		stack->stack_b[stack->length - stack->length_b - 1] =
		stack->stack_a[stack->length - stack->length_a];
		stack->length_b++;
		stack->length_a--;
		ft_realloc_string(stack, 4);
		ft_realloc_string(stack, -1);
	}
	return (1);
}

int	ft_execution_ra(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	if (stack->length_a <= 1)
		return (1);
	first = stack->stack_a[stack->length - stack->length_a];
	while (i < (stack->length_a - 1))
	{
		stack->stack_a[stack->length - stack->length_a + i] =
		stack->stack_a[stack->length - stack->length_a + 1 + i];
		i++;
	}
	stack->stack_a[stack->length - 1] = first;
	ft_realloc_string(stack, 5);
	ft_realloc_string(stack, -1);
	return (1);
}
