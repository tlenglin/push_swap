/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:37:46 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 15:27:43 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int			ft_sorting_algo1_a_bis(t_stack *stack, int nb, t_algo *algo)
{
	while (algo->i < nb)
	{
		if (stack->stack_a[algo->i] > stack->stack_a[algo->i + 1])
		{
			ft_swap_a(algo, stack);
			return (ft_sorting_algo1_a(stack));
		}
		algo->i++;
	}
	return (0);
}

int			ft_sorting_algo1_a(t_stack *stack)
{
	t_algo	algo;
	int		i_min;

	i_min = ft_get_min(stack->stack_a, stack->length_a, stack->length);
	algo.i = i_min;
	ft_sorting_algo1_a_bis(stack, stack->length - 1, &algo);
	if (stack->stack_a[stack->length - 1] > (stack->stack_a[stack->length -
		stack->length_a]) && stack->length - stack->length_a != i_min)
	{
		algo.i = stack->length - 1;
		ft_swap_a(&algo, stack);
		return (ft_sorting_algo1_a(stack));
	}
	algo.i = stack->length - stack->length_a;
	ft_sorting_algo1_a_bis(stack, i_min - 1, &algo);
	ft_pull_up_min_a(stack);
	return (1);
}

int			ft_mini_algo(t_stack *stack)
{
	int a;

	ft_split_stack_a(stack, 5);
	if (stack->stack_b[stack->length - stack->length_b] <
		stack->stack_b[stack->length - stack->length_b + 1])
		ft_execution_sb(stack);
	a = ft_parsing_of_the_real_shit(stack->stack_a, stack->length_a,
		stack->length);
	if (a == 1)
		ft_ra_sa_rra(stack);
	else if (a == 2)
		ft_execution_ra(stack);
	else if (a == 3)
		ft_execution_sa(stack);
	else if (a == 4)
		ft_execution_rra(stack);
	else if (a == 5)
	{
		ft_execution_sa(stack);
		ft_execution_rra(stack);
	}
	ft_execution_pa(stack);
	ft_execution_pa(stack);
	return (0);
}
