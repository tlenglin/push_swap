/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:11:48 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:12:39 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse2(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_ss(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_sb(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 1)
	{
		ft_execution_sa(stack);
		ft_ra_ss_rra(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_execution_sa(stack);
		ft_rr_ss_rrr(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 3 || nb == 4 || nb == 5)
		ft_parse2_bis(nb, stack);
	return (1);
}

int	ft_parse2_bis(int nb, t_stack *stack)
{
	if (nb == 3)
	{
		ft_execution_sa(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_sb(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 4)
	{
		ft_execution_sa(stack);
		ft_ra_ss_rra(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_execution_sa(stack);
		ft_ra_sa_rra(stack);
		ft_pa_pa_pa(stack);
	}
	return (1);
}

int	ft_parse3(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_rb(stack);
		ft_execution_ss(stack);
		ft_execution_pa(stack);
		ft_execution_pa(stack);
		ft_execution_rrb(stack);
		ft_execution_pa(stack);
	}
	else if (nb == 1)
	{
		ft_execution_ss(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_execution_sa(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 3 || nb == 4 || nb == 5)
		ft_parse3_bis(nb, stack);
	return (1);
}

int	ft_parse3_bis(int nb, t_stack *stack)
{
	if (nb == 3)
	{
		ft_execution_rb(stack);
		ft_execution_ss(stack);
		ft_execution_pa(stack);
		ft_execution_rrb(stack);
		ft_execution_pa(stack);
		ft_execution_pa(stack);
	}
	else if (nb == 4)
	{
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	return (1);
}

int	ft_parse4(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_sb(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 1)
	{
		ft_ra_ss_rra(stack);
		ft_execution_sa(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_rr_ss_rrr(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 3 || nb == 4 || nb == 5)
		ft_parse4_bis(nb, stack);
	return (1);
}
