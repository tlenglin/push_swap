/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:42:09 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/31 08:09:28 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_stack_order(t_stack *stack)
{
	int	i;
	int tmp;

	i = 0;
	if (stack->length != stack->length_a)
	{
		return (0);
	}
	tmp = stack->stack_a[0];
	while (i < stack->length)
	{
		if (tmp > stack->stack_a[i])
			return (0);
		tmp = stack->stack_a[i];
		i++;
	}
	return (1);
}

int	ft_check_duplication(t_stack *stack)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	while (i < (stack->length - 1))
	{
		tmp = stack->stack_a[i];
		j = i + 1;
		while (j < stack->length)
		{
			if (tmp == stack->stack_a[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
	{
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_read_arg_bis(char *str, t_stack *stack)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (!(stack->stack_a = ft_memalloc(sizeof(int) * (i ))))
		return (0);
	if (!(stack->stack_b = ft_memalloc(sizeof(int) * (i ))))
		return (0);
	stack->length = i;
	stack->length_a = i;
	stack->length_b = 0;
	stack->instructions = NULL;
	i = 0;
	while (split[i])
	{
		if (ft_check_arg(split[i]) == 0)
			return (0);
		stack->stack_a[i] = ft_atoi(split[i]);
		i++;
	}
	return (1);
	// while (str[i])
	// {
	// 	while (str[i] && str[i] == ' ')
	// 	{
	// 		i++;
	// 	}
	// 	if (str[i] && str[i] != ' ')
	// 	{
	// 		while (str[i] && str[i] != ' ')
	// 		{
	//
	// 		}
	// 	}
	// 	i++;
	// }

}

int	ft_read_arg(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		return (0);
	}
	if (!(stack->stack_a = ft_memalloc(sizeof(int) * (argc - 1))))
		return (0);
	if (!(stack->stack_b = ft_memalloc(sizeof(int) * (argc - 1))))
		return (0);
	stack->length = argc - 1;
	stack->length_a = argc - 1;
	stack->length_b = 0;
	stack->instructions = NULL;
	if (argc == 2)
	{
		if (ft_read_arg_bis(argv[1], stack) == 0)
		{
			return (0);
		}
	}
	else
	{
		while (i < argc)
		{
			if (ft_check_arg(argv[i]) == 0)
			{
				return (0);
			}
			stack->stack_a[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	if (ft_check_duplication(stack) == 0)
	{
		return (0);
	}
	return (1);
}
