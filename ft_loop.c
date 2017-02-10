/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:28:51 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:29:14 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_first_split_loop(t_stack *stack)
{
	int loop;

	loop = 0;
	while (stack->length_a > 6)
	{
		ft_split_stack_a(stack, stack->length_a);
		loop++;
	}
	return (loop);
}

int			ft_second_split_loop(t_stack *stack, int cut)
{
	int loop;

	loop = 0;
	while (cut > 6)
	{
		ft_split_stack_bis_a(stack, cut);
		loop++;
		cut = cut / 2;
	}
	loop--;
	return (loop);
}
