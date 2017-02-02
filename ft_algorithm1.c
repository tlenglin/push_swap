/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:33:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/31 10:41:24 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorting_algo1_a(t_stack *stack)
{
	t_algo	algo;

		// ft_putstr("\nccccccccccccc");
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

	int i_min;

	i_min = ft_get_min(stack->stack_a, stack->length_a, stack->length);
	algo.i = i_min;
	while (algo.i < stack->length - 1)
	{
		if (stack->stack_a[algo.i] > stack->stack_a[algo.i + 1])
		{
			ft_swap_a(&algo, stack);
			return (ft_sorting_algo1_a(stack));
		}
		algo.i++;
		// ft_putnbr(stack->length);
		// ft_putnbr(algo.i);
		// ft_putstr("ooo\n");

	}
	if (stack->stack_a[stack->length - 1] > (stack->stack_a[stack->length - stack->length_a]) && stack->length - stack->length_a != i_min)
	{
		algo.i = stack->length - 1;
		ft_swap_a(&algo, stack);
		return (ft_sorting_algo1_a(stack));
	}
	algo.i = stack->length - stack->length_a;
	while (algo.i < (i_min - 1))
	{
		if (stack->stack_a[algo.i] > stack->stack_a[algo.i + 1])
		{
			ft_swap_a(&algo, stack);
			return (ft_sorting_algo1_a(stack));
		}
		algo.i++;
	}
	return (1);
}

int	ft_sorting_algo1_b(t_stack *stack)
{
	t_algo	algo;
	int		i_min;

	i_min = ft_get_min(stack->stack_b, stack->length_b, stack->length);
	algo.i = i_min;
	while (algo.i < stack->length - 1)
	{
		if (stack->stack_b[algo.i] > stack->stack_b[algo.i + 1])
		{
			ft_swap_b(&algo, stack);
			return (ft_sorting_algo1_b(stack));
		}
		algo.i++;
	}
	if (stack->stack_b[stack->length - 1] > (stack->stack_b[stack->length - stack->length_b]) && stack->length - stack->length_b != i_min)
	{
		algo.i = stack->length - 1;
		ft_swap_b(&algo, stack);
		return (ft_sorting_algo1_b(stack));
	}
	algo.i = stack->length - stack->length_b;
	while (algo.i < (i_min - 1))
	{
		if (stack->stack_b[algo.i] > stack->stack_b[algo.i + 1])
		{
			ft_swap_b(&algo, stack);
			return (ft_sorting_algo1_b(stack));
		}
		algo.i++;
	}
	return (1);
}

int	ft_sorting_algo1(t_stack *stack, int nb)
{
	if (nb == 1)
		ft_sorting_algo1_a(stack);
	else
		return (-1);
	ft_pull_up_min_a(stack);
	return (0);
}
