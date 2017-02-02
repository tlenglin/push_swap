/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:26:10 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/02 15:11:04 by tlenglin         ###   ########.fr       */
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
		else if (c > a)
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
		return (1);
	}
	else if (nb == 1)
	{
		ft_ra_sa_rra(stack);
	}
	else if (nb == 2)
	{
		ft_execution_sa(stack);
	}
	else if (nb == 3)
	{
		ft_parse0(1, stack);
		ft_parse0(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse0(2, stack);
		ft_parse0(1, stack);
	}
	else if (nb == 5)
	{
		ft_parse0(4, stack);
		ft_parse0(2, stack);
	}
	return (1);
}

int	ft_parse1(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_rb_sb_rrb(stack);
	}
	else if (nb == 1)
	{
		ft_rr_ss_rrr(stack);
	}
	else if (nb == 2)
	{
		ft_rb_ss_rrb(stack);
	}
	else if (nb == 3)
	{
		ft_parse1(1, stack);
		ft_parse0(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse0(2, stack);
		ft_parse1(1, stack);
	}
	else if (nb == 5)
	{
		ft_parse1(4, stack);
		ft_parse0(2, stack);
	}
	return (1);
}

int	ft_parse2(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_execution_sb(stack);
	}
	else if (nb == 1)
	{
		ft_ra_ss_rra(stack);
	}
	else if (nb == 2)
	{
		ft_execution_ss(stack);
	}
	else if (nb == 3)
	{
		ft_parse2(1, stack);
		ft_parse0(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse0(2, stack);
		ft_parse2(1, stack);
	}
	else if (nb == 5)
	{
		ft_parse2(4, stack);
		ft_parse0(2, stack);
	}
	return (1);
}

int	ft_parse3(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_parse1(0, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 1)
	{
		ft_parse1(1, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 2)
	{
		ft_parse1(2, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 3)
	{
		ft_parse1(1, stack);
		ft_parse2(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse1(4, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 5)
	{
		ft_parse1(4, stack);
		ft_parse2(2, stack);
	}
	return (1);
}

int	ft_parse4(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_parse2(0, stack);
		ft_parse1(0, stack);
	}
	else if (nb == 1)
	{
		ft_parse2(0, stack);
		ft_parse1(1, stack);
	}
	else if (nb == 2)
	{
		ft_parse2(2, stack);
		ft_parse1(0, stack);
	}
	else if (nb == 3)
	{
		ft_parse2(0, stack);
		ft_parse1(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse2(2, stack);
		ft_parse1(2, stack);
	}
	else if (nb == 5)
	{
		ft_parse4(4, stack);
		ft_parse0(2, stack);
	}
	return (1);
}

int	ft_parse5(int nb, t_stack *stack)
{
	if (nb == 0)
	{
		ft_parse2(0, stack);
		ft_parse3(0, stack);
	}
	else if (nb == 1)
	{
		ft_parse4(1, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 2)
	{
		ft_parse4(2, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 3)
	{
		ft_parse4(1, stack);
		ft_parse2(2, stack);
	}
	else if (nb == 4)
	{
		ft_parse4(4, stack);
		ft_parse2(0, stack);
	}
	else if (nb == 5)
	{
		ft_parse4(4, stack);
		ft_parse2(2, stack);
	}
	return (1);
}
