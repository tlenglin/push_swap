/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 08:24:00 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/31 09:45:14 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorting_algo2_a_bis(t_algo *algo, t_stack *stack)
{
	while ((algo->i < (stack->length - 1)) && ((stack->stack_a[algo->i] < stack->stack_a[algo->i + 1]) && (stack->stack_a[algo->i + 1] < stack->stack_a[stack->length - stack->length_a])))
	{
		algo->i++;
	}
	if (algo->i == (stack->length - 1))
	{
		return (1);
	}
	else
	{
		algo->i++;
		ft_insert(algo, stack);
		if (ft_sorting_algo2_a(stack) == 1)
			return (1);
	}
	return (0);
}

int	ft_sorting_algo2_a(t_stack *stack)
{
	t_algo	algo;

		// ft_putstr("\nbbbbbbbbbbb");
		// ft_putstr("\na_0 ");
		// ft_putnbr(stack->stack_a[0]);
		// ft_putstr("\na_1 ");
		// ft_putnbr(stack->stack_a[1]);
		// ft_putstr("\na_2 ");
		// ft_putnbr(stack->stack_a[2]);
		// ft_putstr("\na_3 ");
		// ft_putnbr(stack->stack_a[3]);
		// ft_putstr("\na_4 ");
		// ft_putnbr(stack->stack_a[4]);
		// ft_putstr("\na_5 ");
		// ft_putnbr(stack->stack_a[5]);
		// ft_putstr("\na_6 ");
		// ft_putnbr(stack->stack_a[6]);
		// ft_putstr("\na_7 ");
		// ft_putnbr(stack->stack_a[7]);
		// ft_putstr("\na_8 ");
		// ft_putnbr(stack->stack_a[8]);
		// ft_putstr("\na_9 ");
		// ft_putnbr(stack->stack_a[9]);
		// ft_putstr("\na_10 ");
		// ft_putnbr(stack->stack_a[10]);
		// ft_putstr("\na_11 ");
		// ft_putnbr(stack->stack_a[11]);
		// ft_putstr("\na_12 ");
		// ft_putnbr(stack->stack_a[12]);
		// ft_putstr("\na_13 ");
		// ft_putnbr(stack->stack_a[13]);
		// ft_putstr("\na_14 ");
		// ft_putnbr(stack->stack_a[14]);
		// ft_putstr("\na_15 ");
		// ft_putnbr(stack->stack_a[15]);
		// ft_putstr("\na_16 ");
		// ft_putnbr(stack->stack_a[16]);
		// ft_putstr("\na_17 ");
		// ft_putnbr(stack->stack_a[17]);
		// ft_putstr("\na_18 ");
		// ft_putnbr(stack->stack_a[18]);
		// ft_putstr("\na_19 ");
		// ft_putnbr(stack->stack_a[19]);
	algo.i = stack->length - stack->length_a;
	if (algo.i == (stack->length - 1))
		return (1);
	algo.min = stack->stack_a[algo.i];
	algo.max = stack->stack_a[algo.i];
	while ((algo.i < (stack->length - 1)) && (stack->stack_a[algo.i] < stack->stack_a[algo.i + 1]))
	{
		algo.i++;
	}
	if (algo.i == (stack->length - 1))
	{
		return (1);
	}
	else if (stack->stack_a[algo.i] > stack->stack_a[algo.i + 1])
	{
		if (stack->stack_a[algo.i + 1] < algo.min)
		{
			algo.min = stack->stack_a[algo.i + 1];
			algo.i++;
			if (ft_sorting_algo2_a_bis(&algo, stack) == 1)
				return (1);
		}
		else
		{
			algo.i++;
			ft_insert(&algo, stack);
			if (ft_sorting_algo2_a(stack) == 1)
				return (1);
		}
	}
	return (0);
}

int	ft_sorting_algo2(t_stack *stack, int nb)
{
	if (nb == 1)
		ft_sorting_algo2_a(stack);
	else
		return (-1);
	ft_pull_up_min_a(stack);
	return (0);
}
