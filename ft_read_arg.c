/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:19:02 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 16:33:55 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_read_arg(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	if (ft_init_struct(argc, stack) == 0)
		return (0);
	if (argc == 2)
	{
		free(stack->stack_a);
		free(stack->stack_b);
		if (ft_read_arg_bis(argv[1], stack) == 0)
			return (0);
	}
	else
	{
		while (i < argc)
		{
			if (ft_check_arg(argv[i]) == 0)
				return (ft_error(stack));
			stack->stack_a[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	if (ft_check_duplication(stack) == 0)
		return (ft_error(stack));
	return (1);
}

int	ft_free_split(char ***split)
{
	int j;

	j = -1;
	while ((*split)[++j])
		free((*split)[j]);
	free(*split);
	*split = NULL;
	return (0);
}

int	ft_read_arg_bis(char *str, t_stack *stack)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	ft_new_strsplit(str, ' ', &split);
	if (split[0] == NULL)
		return (ft_free_split(&split));
	while (split[i])
		i++;
	if (ft_init_struct(i + 1, stack) == 0)
		return (0);
	i = 0;
	while (split[i])
	{
		if (ft_check_arg(split[i]) == 0)
		{
			ft_free_split(&split);
			return (ft_error(stack));
		}
		stack->stack_a[i] = ft_atoi(split[i]);
		i++;
	}
	ft_free_split(&split);
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
			return (0);
		i++;
	}
	if (ft_strlen(str) > 13)
		return (0);
	if (ft_atoi_check(str) == 0)
		return (0);
	return (1);
}

int	ft_atoi_check(char *str)
{
	long			res;
	int				sign;
	unsigned int	i;

	sign = 1;
	i = 0;
	res = 0;
	if (str == NULL)
		return (0);
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((res == 214748364) && (str[i] == 8))
			return (-2147483648);
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (res * sign > 2147483647 || res * sign < -2147483648)
		return (0);
	return (1);
}
