/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:17:45 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:18:03 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
