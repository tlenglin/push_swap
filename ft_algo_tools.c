/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 08:25:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:33:28 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_merge_stack(t_stack *stack)
{
	int count;

	count = 0;
	ft_pull_up_min_a(stack);
	ft_pull_up_min_b(stack);
	while (stack->length_b > 0)
	{
		while (stack->stack_a[stack->length - stack->length_a] <
			stack->stack_b[stack->length - stack->length_b] && count <
			stack->length_a)
		{
			ft_execution_ra(stack);
			count++;
		}
		ft_execution_pa(stack);
	}
	return (1);
}

int	ft_swap_a(t_algo *algo, t_stack *stack)
{
	ft_pull_up_a(algo->i, stack);
	ft_execution_sa(stack);
	return (1);
}

int	ft_swap_b(t_algo *algo, t_stack *stack)
{
	ft_pull_up_b(algo->i, stack);
	ft_execution_sb(stack);
	return (1);
}

int	ft_power(int i)
{
	int j;
	int result;

	result = 1;
	j = 0;
	while (j < i)
	{
		result = result * 2;
		j++;
	}
	return (result);
}
