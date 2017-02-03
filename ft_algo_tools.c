/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 08:25:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/02 18:56:40 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_insert(t_algo *algo, t_stack *stack)
{
	int i;

	i = algo->i - 1;
	while (i != 0 && !((stack->stack_a[algo->i] < stack->stack_a[i] && stack->stack_a[algo->i] > stack->stack_a[i - 1])))
	{
		i--;
	}
	ft_pull_up_a(algo->i, stack);
	ft_execution_pb(stack);
	algo->i = (stack->length) - (algo->i - i);
	ft_pull_up_a(algo->i, stack);
	ft_execution_pa(stack);
	return (ft_sorting_algo2_a(stack));
}

int	ft_swap_a(t_algo *algo, t_stack *stack)
{
	ft_pull_up_a(algo->i, stack);
	ft_execution_sa(stack);
	return (1);
}

int	ft_swap_b(t_algo *algo, t_stack *stack)
{
	ft_pull_up_b(algo->i, stack);
	ft_execution_sb(stack);
	return (1);
}

int	ft_get_min(int	*tab, int length_s, int length)
{
	int	i;
	int min;
	int i_min;

	i = length - length_s;
	min = tab[i];
	i_min = i;
	while (i < length)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

int	ft_get_max(int *tab, int length_s, int length)
{
	int	i;
	int max;
	int i_max;

	i = length - length_s;
	max = tab[i];
	i_max = i;
	while (i < length)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	ft_get_base_cut(int length_s)
{
	int i;

	i = 6;
	while ((i * 2) <= length_s)
	{
		i = i * 2;
	}
	return (i);
}

int	ft_get_value(int *tab, int length_s, int length, int cut)
{
	int	i;
	int j;
	int count;
	int	tab_bis[length_s];

	i = length - length_s;
	while (i < length)
	{
		j = length - length_s;
		count = 0;
		while (j < length)
		{
			if (tab[i] < tab[j])
				count++;
			j++;
		}
		tab_bis[length_s - 1 - count] = tab[i];
		i++;
	}
	// ft_putstr("\ntab trie");
	// ft_putstr("\nt_0 ");
	// ft_putnbr(tab_bis[0]);
	// ft_putstr("\nt_1 ");
	// ft_putnbr(tab_bis[1]);
	// ft_putstr("\nt_2 ");
	// ft_putnbr(tab_bis[2]);
	// ft_putstr("\nt_3 ");
	// ft_putnbr(tab_bis[3]);
	// ft_putstr("\nt_4 ");
	// ft_putnbr(tab_bis[4]);
	// ft_putstr("\nt_5 ");
	// ft_putnbr(tab_bis[5]);
	// ft_putstr("\nt_6 ");
	// ft_putnbr(tab_bis[6]);
	// ft_putstr("\nt_7 ");
	// ft_putnbr(tab_bis[7]);
	// ft_putstr("\nt_8 ");
	// ft_putnbr(tab_bis[8]);
	// ft_putstr("\nt_9 ");
	// ft_putnbr(tab_bis[9]);
	// ft_putstr("\nt_10 ");
	// ft_putnbr(tab_bis[10]);
	// ft_putstr("\nt_11 ");
	// ft_putnbr(tab_bis[11]);
	// ft_putstr("\nt_12 ");
	// ft_putnbr(tab_bis[12]);
	// ft_putstr("\nt_13 ");
	// ft_putnbr(tab_bis[13]);
	// ft_putstr("\ncut - 1 = ");
	// ft_putnbr(cut - 1);
	// ft_putchar('\n');
	return (tab_bis[cut - 1]);
}

int	ft_get_medium(int *tab, int length_s, int length, int len)
{
	int	i;
	int j;
	int count;
	int	tab_bis[len];

	i = length - length_s;
	// ft_putstr("debut de get_medium\n");
	// ft_putstr("i = ");
	// ft_putnbr(i);
	// ft_putchar('\n');
	// ft_putstr("len = ");
	// ft_putnbr(len);
	// ft_putchar('\n');
	while (i < (length - length_s + len))
	{
		j = length - length_s;
		count = 0;
		while (j < (length - length_s + len))
		{
			if (tab[i] < tab[j])
				count++;
			j++;
		}
		// ft_putstr("tab[i] = ");
		// ft_putnbr(tab[i]);
		// ft_putchar('\n');
		// ft_putstr("count = ");
		// ft_putnbr(count);
		// ft_putchar('\n');
		// ft_putstr("len - 1 - count = ");
		// ft_putnbr(len - 1 - count);
		// ft_putchar('\n');
		tab_bis[len - 1 - count] = tab[i];
		i++;
	}
	// ft_putstr("tab_bis[len / 2] = ");
	// ft_putnbr(tab_bis[len / 2]);
	// ft_putchar('\n');
	// ft_putstr("fin de get_medium\n");
	return (tab_bis[len / 2]);
}

int	ft_pull_up_b(int i, t_stack *stack)
{
	int	up;
	int	down;
	int	j;

	j = 0;
	up = i - (stack->length - stack->length_b);
	down = (stack->length - 1) - i + 1;
	if (up <= down)
	{
		while (j < up)
		{
			ft_execution_rb(stack);
			j++;
		}
	}
	else
	{
		while (j < down)
		{
			ft_execution_rrb(stack);
			j++;
		}
	}
	return (0);
}

int	ft_pull_up_a(int i, t_stack *stack)
{
	int	up;
	int	down;
	int	j;

	j = 0;
	up = i - (stack->length - stack->length_a);
	down = (stack->length - 1) - i + 1;
	if (up <= down)
	{
		while (j < up)
		{
			ft_execution_ra(stack);
			j++;
		}
	}
	else
	{
		while (j < down)
		{
			ft_execution_rra(stack);
			j++;
		}
	}
	return (0);
}

int	ft_pull_up_min_b(t_stack *stack)
{
	t_algo	algo;

	algo.i = stack->length - stack->length_b;
	algo.min = stack->stack_b[stack->length - stack->length_b];
	if (algo.i == (stack->length - 1))
		return (1);
	algo.i++;
	while (algo.i < (stack->length) && stack->stack_b[algo.i - 1] < stack->stack_b[algo.i])
	{
		algo.i++;
	}
	if (algo.i != (stack->length))
	{
		ft_pull_up_b(algo.i, stack);
	}
	return (0);
}

int	ft_pull_up_min_a(t_stack *stack)
{
	t_algo	algo;

	algo.i = stack->length - stack->length_a;
	algo.min = stack->stack_a[stack->length - stack->length_a];
	if (algo.i == (stack->length - 1))
		return (1);
	algo.i++;
	while (algo.i < (stack->length) && stack->stack_a[algo.i - 1] < stack->stack_a[algo.i])
	{
		algo.i++;
	}
	if (algo.i != (stack->length))
	{
		ft_pull_up_a(algo.i, stack);
	}
	return (0);
}

int ft_power(int i)
{
	int j;
	int result;

	result = 1;
	j = 0;
	while (j < i)
	{
		result = result * 2;
		j++;
	}
	return (result);
}
