/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:21:56 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:23:32 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_split_stack(t_stack *stack)
{
	int i;

	i = stack->length_a / 2;
	while (i > 0)
	{
		ft_execution_pb(stack);
		i--;
	}
	return (1);
}

int			ft_split_a(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->length_a > 11)
	{
		ft_split_stack_bis_a(stack, stack->length_a);
	}
	if (stack->length_a != 6)
	{
		while (i < 6)
		{
			ft_execution_pb(stack);
			i++;
		}
	}
	return (1);
}

int			ft_first_split_a(t_stack *stack)
{
	int	value;
	int	cut;
	int	count;

	cut = ft_get_base_cut(stack->length_a);
	value = ft_get_value(stack->stack_a, stack->length_a, stack->length,
		stack->length_a - cut);
	count = stack->length_a - cut;
	while (count > 0)
	{
		if (stack->stack_a[stack->length - stack->length_a] > value)
			ft_execution_ra(stack);
		else
		{
			ft_execution_pb(stack);
			count--;
		}
	}
	return (cut);
}

int			ft_split_stack_a(t_stack *stack, int len)
{
	int	medium;
	int	count;
	int count_bis;

	medium = ft_get_medium(stack->stack_a, stack->length_a, stack->length, len);
	count = 0;
	count_bis = 0;
	while (count < (len / 2))
	{
		if (stack->stack_a[stack->length - stack->length_a] >= medium)
		{
			ft_execution_ra(stack);
			count_bis++;
		}
		else
		{
			ft_execution_pb(stack);
			count++;
		}
	}
	while (count_bis-- > 0)
		ft_execution_rra(stack);
	return (1);
}

int			ft_split_stack_bis_a(t_stack *stack, int len)
{
	int	medium;
	int	count;
	int count_bis;

	medium = ft_get_medium(stack->stack_a, stack->length_a, stack->length, len);
	count = 0;
	count_bis = 0;
	while (count < (len / 2))
	{
		if (stack->stack_a[stack->length - stack->length_a] >= medium)
		{
			ft_execution_ra(stack);
			count_bis++;
		}
		else
		{
			ft_execution_pb(stack);
			count++;
		}
	}
	while (count_bis-- > 0)
		ft_execution_rra(stack);
	return (1);
}
