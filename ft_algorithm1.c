/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:33:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 19:38:36 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_sorting_algo4_b(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->length_b < 6)
		return (1);
	ft_split_stack_b(stack, 6);
	ft_sorting_six_elem(stack);
	return (1);
}

int			ft_sorting_six_elem(t_stack *stack)
{
	int			a;
	int			b;
	t_fct_bis	*ft_shitty_parsing;

	ft_shitty_parsing = ft_set_shitty_parsing();
	a = ft_parsing_of_the_real_shit(stack->stack_a, stack->length_a,
		stack->length);
	b = ft_parsing_of_the_real_shit(stack->stack_b, stack->length_b,
		stack->length);
	ft_shitty_parsing[a](b, stack);
	return (1);
}

int			ft_sorting_algo4_a(t_stack *stack)
{
	int i;

	i = 0;
	ft_split_stack_bis_a(stack, 6);
	ft_sorting_six_elem(stack);
	return (1);
}
