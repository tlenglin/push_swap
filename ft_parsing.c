/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:26:10 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/03 18:35:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_parsing_of_the_real_shit(int *tab, int length_s, int length)
{
	int a;
	int b;
	int c;

	a = tab[length - length_s];
	b = tab[length - length_s + 1];
	c = tab[length - length_s + 2];
	if (a < b)
	{
		if (b < c)
		{
			return (0);
		}
		else if (a < c)
		{
			return (1);
		}
		else
		{
			return (4);
		}
	}
	else
	{
		if (b > c)
		{
			return (5);
		}
		else if (c < a)
		{
			return (2);
		}
		else
		{
			return (3);
		}
	}
	return (-1);
}

int	ft_parse0(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_rb(stack);
		ft_execution_sb(stack);
		ft_execution_pa(stack);
		ft_execution_pa(stack);
		ft_execution_rrb(stack);
		ft_execution_pa(stack);
	}
	else if (nb == 1)
	{
		ft_execution_sb(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 3)
	{
		ft_execution_rb(stack);
		ft_execution_sb(stack);
		ft_execution_pa(stack);
		ft_execution_rrb(stack);
		ft_execution_pa(stack);
		ft_execution_pa(stack);
	}
	else if (nb == 4)
	{
		ft_execution_sb(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_pa_pa_pa(stack);
	}
	return (1);
}

int	ft_parse1(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_rr(stack);
		ft_execution_ss(stack);
		ft_execution_rra(stack);
		ft_execution_pa(stack);
		ft_execution_pa(stack);
		ft_execution_rrb(stack);
		ft_execution_pa(stack);
	}
	else if (nb == 1)
	{
		ft_ra_ss_rra(stack);
		ft_pa_sb_pa_pa(stack);
	}
	else if (nb == 2)
	{
		ft_rr_ss_rrr(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 3)
	{
		ft_rr_ss_rrr(stack);
		ft_execution_sb(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 4)
	{
		ft_ra_ss_rra(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 5)
	{
		ft_ra_sa_rra(stack);
		ft_pa_pa_pa(stack);
	}
	return (1);
}

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
	else if (nb == 3)
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
	else if (nb == 3)
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
	else if (nb == 3)
	{
		ft_rr_ss_rrr(stack);
		ft_execution_ss(stack);
		ft_pa_pa_pa(stack);
	}
	else if (nb == 4)
	{
		ft_ra_ss_rra(stack);
		ft_execution_ss(stack);
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

int	ft_parse5(int nb, t_stack *stack)
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
	else if (nb == 3)
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
		ft_execution_ss(stack);
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
