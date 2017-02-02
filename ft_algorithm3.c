/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:21:38 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/02 15:13:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_stack(t_stack *stack)
{
	int i;

	i = stack->length_a / 2;
	while (i > 0)
	{
		ft_execution_pb(stack);
		i--;
	}
	return (1);
}

int	ft_split_a(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->length_a > 11)
	{
		ft_split_stack_a(stack, stack->length_a);
	}
	if (stack->length_a != 6)
	{
		while (i < 6)
		{
			ft_execution_pb(stack);
			i++;
		}
	}
	return (1);
}

int	ft_first_split_a(t_stack *stack)
{
	int	value;
	int	cut;
	int	count;

	cut = ft_get_base_cut(stack->length_a);
	value = ft_get_value(stack->stack_a, stack->length_a, stack->length, cut);
	count = 0;
	while (count < (stack->length - cut))
	{
		if (stack->stack_a[0] >= value)
		{
			ft_execution_ra(stack);
		}
		else
		{
			ft_execution_pb(stack);
			count++;
		}
	}
	return (cut);
}

int	ft_first_split_b(t_stack *stack)
{
	int	value;
	int	cut;
	int	count;

	cut = ft_get_base_cut(stack->length_b);
	value = ft_get_value(stack->stack_b, stack->length_b, stack->length, cut);
	count = 0;
	while (count < (stack->length - cut))
	{
		if (stack->stack_a[0] < value)
		{
			ft_execution_rb(stack);
		}
		else
		{
			ft_execution_pa(stack);
			count++;
		}
	}
	return (cut);
}

int	ft_first_split_loop(t_stack *stack)
{
	int loop;

	loop = 0;
	while (stack->length_a != 6)
	{
		ft_split_stack_a(stack, stack->length_a);
		loop++;
	}
	return (loop);
}

int	ft_second_split_loop(t_stack *stack, int cut)
{
	int loop;

	loop = 0;
	while (cut != 6)
	{
		ft_split_stack_a(stack, stack->length_a);
		loop++;
		cut = cut / 2;
	}
	return (loop);
}

int	ft_split_stack_a(t_stack *stack, int len)
{
	int	medium;
	int	count;

	medium = ft_get_medium(stack->stack_a, stack->length_a, stack->length, len);
	count = 0;
	while (count < (len / 2))
	{
		if (stack->stack_a[0] >= medium)
		{
			ft_execution_ra(stack);
		}
		else
		{
			ft_execution_pb(stack);
			count++;
		}
	}
	return (1);
}

int	ft_split_stack_b(t_stack *stack, int len)
{
	int	medium;
	int	count;

	medium = ft_get_medium(stack->stack_b, stack->length_b, stack->length, len);
	count = 0;
	while (count < (len / 2))
	{
		if (stack->stack_a[0] <= medium)
		{
			ft_execution_rb(stack);
		}
		else
		{
			ft_execution_pa(stack);
			count++;
		}
	}
	return (1);
}

int	ft_merge_stack(t_stack *stack)
{
	int count;

	count = 0;
	ft_pull_up_min_a(stack);
	ft_pull_up_min_b(stack);
	while (stack->length_b > 0)
	{
		while (stack->stack_a[stack->length - stack->length_a] < stack->stack_b[stack->length - stack->length_b] && count < stack->length_a)
		{
			ft_execution_ra(stack);
			count++;
			// ft_putnbr(count);
		}
		// ft_putnbr(count);
		ft_execution_pa(stack);
	}
	return (1);
}

int	ft_sorting_algo3(t_stack *stack)
{
	ft_split_stack(stack);
	ft_sorting_algo1_a(stack);
	ft_sorting_algo1_b(stack);
	ft_merge_stack(stack);
	ft_pull_up_min_a(stack);
	return (0);
}

int	ft_sorting_algo4_b(t_stack *stack)
{
	int i;

	i = 0;
	ft_split_stack_b(stack, 6);
	ft_sorting_six_elem(stack);
	while (i < 3)
	{
		ft_execution_pa(stack);
	}
	return (1);
}

int ft_sorting_six_elem(t_stack *stack)
{
	int a;
	int b;
	p_fct_bis	*ft_shitty_parsing;

	ft_shitty_parsing = ft_set_shitty_parsing();
	a = ft_parsing_of_the_real_shit(stack->stack_a, stack->length_a, stack->length);
	b = ft_parsing_of_the_real_shit(stack->stack_b, stack->length_b, stack->length);
	ft_shitty_parsing[b](a, stack);
	return (1);
}

p_fct_bis	*ft_set_shitty_parsing(void)
{
	static p_fct_bis	ft_shitty_parsing[6] = {&ft_parse0,&ft_parse1,&ft_parse2,&ft_parse3,&ft_parse4,&ft_parse5};

	return (ft_shitty_parsing);
}

int	ft_sorting_algo4_a(t_stack *stack)
{
	int i;

	i = 0;
	ft_split_stack_a(stack, 6);
	ft_sorting_six_elem(stack);
	while (i < 3)
	{
		ft_execution_pa(stack);
	}
	return (1);
}

int	ft_stupid_function(t_stack *stack)
{
	ft_split_stack_b(stack, 12);
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	return (1);
}

int	ft_big_fucking_recursive(t_stack *stack, int loop)
{
	int j;

	if (loop == 1)
	{
		ft_stupid_function(stack);
	}
	else
	{
		ft_split_stack_b(stack, 6 * ft_power(loop));
		j = 0;
		while (j < 3 * ft_power(loop))
		{
			ft_execution_pb(stack);
			j++;
		}
		loop--;
		ft_big_fucking_recursive(stack, loop);
		ft_big_fucking_recursive(stack, loop);
	}
	return (1);
}

int	ft_last_sorting_ever(t_stack *stack)
{
	int max;

	max = 0;
	while (stack->length_b > 0)
	{
		max = ft_get_max(stack->stack_b, stack->length_b, stack->length);
		ft_pull_up_b(max, stack);
		ft_execution_pa(stack);
	}
	return (1);
}

int ft_here_comes_the_split(t_stack *stack)
{
	int cut;
	int loop;

	if (stack->length_b < 6)
	{
		ft_last_sorting_ever(stack);
		return (1);
	}
	cut = ft_first_split_b(stack);
	loop = ft_second_split_loop(stack, cut);
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	if (loop > 0)
		ft_big_fucking_recursive(stack, loop);
	ft_here_comes_the_split(stack/*, cut*/);
	return (1);
}

int	ft_fat_algo(t_stack *stack)
{
	int loop;
	int cut;

	cut = ft_first_split_a(stack);
	loop = ft_first_split_loop(stack) - 1;
	ft_sorting_algo4_a(stack);
	ft_sorting_algo4_b(stack);
	if (loop > 0)
		ft_big_fucking_recursive(stack, loop);
	ft_here_comes_the_split(stack/*, cut*/);
	return (0);
}
