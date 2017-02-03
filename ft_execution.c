/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 18:11:54 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/03 12:50:33 by tlenglin         ###   ########.fr       */
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
		// ft_putnbr(stack->length_a);

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
	// ft_putnbr(first);
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

int	ft_execution_rb(t_stack *stack)
{
	int	i;
	int	first;

	i = 0;
	if (stack->length_b <= 1)
		return (1);
	first = stack->stack_b[stack->length - stack->length_b];
	while (i < (stack->length_b - 1))
	{
		stack->stack_b[stack->length - stack->length_b + i] =
		stack->stack_b[stack->length - stack->length_b + 1 + i];
		i++;
	}
	stack->stack_b[stack->length - 1] = first;
	ft_realloc_string(stack, 6);
	ft_realloc_string(stack, -1);
	return (1);
}

// int	ft_execution_rr(t_stack *stack)
// {
// 	ft_execution_ra(stack);
// 	ft_execution_rb(stack);
// 	return (1);
// }

int	ft_execution_rra(t_stack *stack)
{
	int	i;
	int	last;

	i = 0;
	if (stack->length_a <= 1)
		return (1);
	last = stack->stack_a[stack->length - 1];
	while (i < (stack->length_a - 1))
	{
		stack->stack_a[stack->length - 1 - i] =
		stack->stack_a[stack->length - i - 2];
		i++;
	}
	stack->stack_a[stack->length - stack->length_a] = last;
	ft_realloc_string(stack, 7);
	ft_realloc_string(stack, -1);
	return (1);
}

int	ft_execution_rrb(t_stack *stack)
{
	int	i;
	int	last;

	i = 0;
	if (stack->length_b <= 1)
		return (1);
	last = stack->stack_b[stack->length - 1];
	while (i < (stack->length_b - 1))
	{
		stack->stack_b[stack->length - 1 - i] =
		stack->stack_b[stack->length - i - 2];
		i++;
	}
	stack->stack_b[stack->length - stack->length_b] = last;
	ft_realloc_string(stack, 8);
	ft_realloc_string(stack, -1);
	return (1);
}

int	ft_execution_ss(t_stack *stack)
{
	ft_execution_sa(stack);
	ft_execution_sb(stack);
	return (1);
}

int	ft_execution_rr(t_stack *stack)
{
	ft_execution_ra(stack);
	ft_execution_rb(stack);
	return (1);
}

int	ft_execution_rrr(t_stack *stack)
{
	ft_execution_rra(stack);
	ft_execution_rrb(stack);
	return (1);
}

int	ft_ra_sa_rra(t_stack *stack)
{
	ft_execution_ra(stack);
	ft_execution_sa(stack);
	ft_execution_rra(stack);
	return (1);
}

int	ft_rb_sb_rrb(t_stack *stack)
{
	ft_execution_rb(stack);
	ft_execution_sb(stack);
	ft_execution_rrb(stack);
	return (1);
}

int	ft_rr_ss_rrr(t_stack *stack)
{
	ft_execution_rr(stack);
	ft_execution_ss(stack);
	ft_execution_rrr(stack);
	return (1);
}

int	ft_rb_ss_rrb(t_stack *stack)
{
	ft_execution_rb(stack);
	ft_execution_ss(stack);
	ft_execution_rrb(stack);
	return (1);
}

int	ft_ra_ss_rra(t_stack *stack)
{
	ft_execution_ra(stack);
	ft_execution_ss(stack);
	ft_execution_rra(stack);
	return (1);
}

int	ft_pa_pa_pa(t_stack *stack)
{
	ft_execution_pa(stack);
	ft_execution_pa(stack);
	ft_execution_pa(stack);
	return (1);
}

int	ft_pa_sb_pa_pa(t_stack *stack)
{
	ft_execution_pa(stack);
	ft_execution_sb(stack);
	ft_execution_pa(stack);
	ft_execution_pa(stack);
	return (1);
}
