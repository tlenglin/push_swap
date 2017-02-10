/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:42:09 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 14:40:39 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_check_stack_order(t_stack *stack)
{
	int	i;
	int tmp;

	i = 0;
	if (stack->length != stack->length_a)
	{
		return (0);
	}
	tmp = stack->stack_a[0];
	while (i < stack->length)
	{
		if (tmp > stack->stack_a[i])
			return (0);
		tmp = stack->stack_a[i];
		i++;
	}
	return (1);
}

int	ft_check_duplication(t_stack *stack)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	while (i < (stack->length - 1))
	{
		tmp = stack->stack_a[i];
		j = i + 1;
		while (j < stack->length)
		{
			if (tmp == stack->stack_a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free(stack->stack_a);
	stack->stack_a = NULL;
	free(stack->stack_b);
	stack->stack_b = NULL;
	return (0);
}

int	ft_init_struct(int argc, t_stack *stack)
{
	if (!(stack->stack_a = ft_memalloc(sizeof(int) * (argc - 1) + 8)))
		return (0);
	if (!(stack->stack_b = ft_memalloc(sizeof(int) * (argc - 1) + 8)))
	{
		free(stack);
		return (0);
	}
	stack->length = argc - 1;
	stack->length_a = argc - 1;
	stack->length_b = 0;
	stack->instructions = NULL;
	return (1);
}
