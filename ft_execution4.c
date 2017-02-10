/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execution4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:18:14 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:18:33 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
