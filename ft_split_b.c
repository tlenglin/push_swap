/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:22:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:24:26 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_first_split_b(t_stack *stack)
{
	int	value;
	int	cut;
	int	count;

	cut = ft_get_base_cut(stack->length_b);
	if (cut == stack->length_b)
		return (ft_second_split_b(stack));
	value = ft_get_value(stack->stack_b, stack->length_b, stack->length,
		stack->length_b - cut);
	count = cut;
	while (count > 0)
	{
		if (stack->stack_b[stack->length - stack->length_b] <= value)
			ft_execution_rb(stack);
		else
		{
			ft_execution_pa(stack);
			count--;
		}
	}
	return (cut);
}

int			ft_second_split_b(t_stack *stack)
{
	int	value;
	int	cut;
	int	count;

	cut = ft_get_base_cut(stack->length_b);
	value = ft_get_value(stack->stack_b, stack->length_b, stack->length,
		stack->length_b - cut);
	count = cut;
	while (count > 0)
	{
		if (stack->stack_b[stack->length - stack->length_b] < value)
			ft_execution_rb(stack);
		else
		{
			ft_execution_pa(stack);
			count--;
		}
	}
	return (cut);
}

int			ft_split_stack_b(t_stack *stack, int len)
{
	int	medium;
	int	count;
	int count_bis;

	medium = ft_get_medium(stack->stack_b, stack->length_b, stack->length, len);
	count = 0;
	count_bis = 0;
	while (count < (len / 2))
	{
		if (stack->stack_b[stack->length - stack->length_b] < medium)
		{
			ft_execution_rb(stack);
			count_bis++;
		}
		else
		{
			ft_execution_pa(stack);
			count++;
		}
	}
	while (count_bis-- > 0)
		ft_execution_rrb(stack);
	return (1);
}
