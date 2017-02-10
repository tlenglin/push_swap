/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:12:51 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 10:42:46 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_parse4_bis(int nb, t_stack *stack)
{
	if (nb == 3)
	{
		ft_rr_ss_rrr(stack);
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 4)
	{
		ft_ra_ss_rra(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_ra_sa_rra(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	return (1);
}

int			ft_parse5(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_ss(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 1)
	{
		ft_execution_sa(stack);
		ft_ra_ss_rra(stack);
		ft_execution_sa(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_execution_sa(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 3 || nb == 4 || nb == 5)
		ft_parse5_bis(nb, stack);
	return (1);
}

int			ft_parse5_bis(int nb, t_stack *stack)
{
	if (nb == 3)
	{
		ft_execution_sa(stack);
		ft_rr_ss_rrr(stack);
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 4)
	{
		ft_execution_sa(stack);
		ft_ra_ss_rra(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_execution_sa(stack);
		ft_ra_sa_rra(stack);
		ft_execution_sa(stack);
		ft_pa_pa_pa(stack);
	}
	return (1);
}

t_fct_bis	*ft_set_shitty_parsing(void)
{
	static t_fct_bis	ft_shitty_parsing[6] =
	{&ft_parse0, &ft_parse1, &ft_parse2, &ft_parse3, &ft_parse4, &ft_parse5};

	return (ft_shitty_parsing);
}
