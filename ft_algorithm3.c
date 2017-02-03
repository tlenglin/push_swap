/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:21:38 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/03 19:05:04 by tlenglin         ###   ########.fr       */
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
	ft_putstr("cut = ");
	ft_putnbr(cut);
	ft_putchar('\n');

	value = ft_get_value(stack->stack_a, stack->length_a, stack->length, stack->length_a - cut);
	count = stack->length_a - cut;
	ft_putstr("value = ");
	ft_putnbr(value);
	ft_putchar('\n');
	ft_putstr("stack->length = ");
	ft_putnbr(stack->length);
	ft_putchar('\n');
	ft_putstr("stack->length_a = ");
	ft_putnbr(stack->length_a);
	ft_putchar('\n');
	while (count > 0)
	{
		if (stack->stack_a[stack->length - stack->length_a] > value)
		{
			ft_execution_ra(stack);
		}
		else
		{
			ft_putstr("stack->stack_a[0] = ");
			ft_putnbr(stack->stack_a[stack->length - stack->length_a]);
			ft_putchar('\n');
			ft_execution_pb(stack);
			count--;
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
	ft_putstr("cut = ");
	ft_putnbr(cut);
	ft_putchar('\n');
	value = ft_get_value(stack->stack_b, stack->length_b, stack->length, stack->length_b - cut);
	count = cut;
	ft_putstr("value = ");
	ft_putnbr(value);
	ft_putchar('\n');
	ft_putstr("stack->length = ");
	ft_putnbr(stack->length);
	ft_putchar('\n');
	ft_putstr("stack->length_b = ");
	ft_putnbr(stack->length_b);
	ft_putchar('\n');
	while (count > 0)
	{
		if (stack->stack_b[stack->length - stack->length_b] <= value)
		{
			ft_execution_rb(stack);
		}
		else
		{
			ft_putstr("stack->stack_b[0] = ");
			ft_putnbr(stack->stack_b[stack->length - stack->length_b]);
			ft_putchar('\n');
			ft_execution_pa(stack);
			count--;
		}
	}
	return (cut);
}

int	ft_first_split_loop(t_stack *stack)
{
	int loop;

	loop = 0;
	while (stack->length_a > 6)
	{
		ft_putstr("xxx\n");
		ft_putstr("stack->length_a = ");
		ft_putnbr(stack->length_a);
		ft_putchar('\n');
		ft_split_stack_a(stack, stack->length_a);
		loop++;
	}
	return (loop);
}

int	ft_second_split_loop(t_stack *stack, int cut)
{
	int loop;

	loop = 0;
	while (cut > 6)
	{
		ft_split_stack_a(stack, cut);
		loop++;
		cut = cut / 2;
	}
	return (loop);
}

int	ft_split_stack_a(t_stack *stack, int len)
{
	int	medium;
	int	count;
	int count_bis;

	medium = ft_get_medium(stack->stack_a, stack->length_a, stack->length, len);
	count = 0;
	count_bis = 0;
	ft_putstr("medium = ");
	ft_putnbr(medium);
	ft_putchar('\n');
	ft_putstr("len / 2 = ");
	ft_putnbr(len / 2);
	ft_putchar('\n');
	while (count < (len / 2))
	{
		if (stack->stack_a[stack->length - stack->length_a] >= medium)
		{
			ft_execution_ra(stack);
			count_bis++;
		}
		else
		{
			ft_putstr("value pushed = ");
			ft_putnbr(stack->stack_a[stack->length - stack->length_a]);
			ft_putchar('\n');
			ft_execution_pb(stack);

			count++;
		}
	}
	while (count_bis > 0)
	{
		ft_execution_rra(stack);
		count_bis--;
	}
	return (1);
}

int	ft_split_stack_b(t_stack *stack, int len)
{
	int	medium;
	int	count;
	int count_bis;

	medium = ft_get_medium(stack->stack_b, stack->length_b, stack->length, len);
	count = 0;
	count_bis = 0;
	ft_putstr("medium = ");
	ft_putnbr(medium);
	ft_putchar('\n');
	ft_putstr("len / 2 = ");
	ft_putnbr(len / 2);
	ft_putchar('\n');
	while (count < (len / 2))
	{
		if (stack->stack_b[stack->length - stack->length_b] < medium)
		{
			ft_execution_rb(stack);
			count_bis++;
		}
		else
		{
			ft_execution_pa(stack);
			count++;
		}
	}
	while (count_bis > 0)
	{
		ft_execution_rrb(stack);
		count_bis--;
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
	if (stack->length_b < 6)
		return (1);
	ft_putstr("rrrr\n");
	ft_split_stack_b(stack, 6);
	ft_putstr("debut algo b\n");
	ft_debug(stack);
	ft_sorting_six_elem(stack);
	// while (i < 3)
	// {
	// 	ft_execution_pa(stack);
	// 	i++;
	// }
	ft_putstr("fin algo_b\n");
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
	ft_putstr("a = ");
	ft_putnbr(a);
	ft_putstr("b = ");
	ft_putnbr(b);
	ft_debug(stack);
	ft_shitty_parsing[a](b, stack);
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
	// ft_putstr("uuu\n");
	ft_split_stack_a(stack, 6);
	// ft_debug(stack);
	// ft_putstr("vvv\n");
	ft_sorting_six_elem(stack);
	// ft_putstr("www\n");
	// while (i < 3)
	// {
	// 	ft_putstr("xxx\n");
	// 	ft_execution_pa(stack);
	// 	i++;
	// }
	// ft_putstr("yyy\n");
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

	ft_putstr("here come the split\n");
	if (stack->length_b < 6)
	{
		ft_last_sorting_ever(stack);
		return (1);
	}
	ft_putstr("avant first_split_b\n");

	cut = ft_first_split_b(stack);
	ft_putstr("apres first_split_b\n");
	ft_debug(stack);

	loop = ft_second_split_loop(stack, cut);
	ft_putstr("loop = ");
	ft_putnbr(loop);
	ft_putchar('\n');
	ft_putstr("apres second_split_loop\n");
	ft_debug(stack);

	ft_sorting_algo4_a(stack);
	ft_putstr("apres algo_a\n");
	ft_debug(stack);

	ft_sorting_algo4_b(stack);
	ft_putstr("apres algo_b\n");
	ft_debug(stack);

	if (loop > 0)
		ft_big_fucking_recursive(stack, loop);
	ft_here_comes_the_split(stack/*, cut*/);
	return (1);
}

int	ft_fat_algo(t_stack *stack)
{
	int loop;
	int cut;
	int i;

	i = 1;
	if (stack->length_a < 6)
		return (ft_sorting_algo1_a(stack));
	ft_putstr("etat initial\n");
	ft_debug(stack);

	cut = ft_first_split_a(stack);
	ft_putstr("first split base 6 fini\n");
	ft_debug(stack);
	// ft_print_instructions(stack->instructions);
	// ft_putstr("ttt\n");
	loop = ft_first_split_loop(stack) - 1;
	ft_putstr("split loop fini\n");
	ft_debug(stack);

	ft_sorting_algo4_a(stack);
	ft_putstr("eee\n");

	ft_debug(stack);
	ft_sorting_algo4_b(stack);
	ft_putstr("pppp\n");
	ft_debug(stack);

	ft_putstr("fff\n");

	while (i < loop + 1)
	{
		ft_big_fucking_recursive(stack, i);
		ft_putstr("ggg\n");

		i++;
	}
	ft_putstr("hhh\n");

	ft_here_comes_the_split(stack/*, cut*/);
	ft_putstr("iii\n");
	ft_debug(stack);
	return (0);
}
