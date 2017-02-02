/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:42:36 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/31 14:18:35 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_check_instructions(char *line, t_stack *stack)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	j = 0;
	if (ft_strcmp(line, "sa") == 0)
	{
		i = 1;
	}
	else if (ft_strcmp(line, "sb") == 0)
	{
		i = 2;
	}
	else if (ft_strcmp(line, "pa") == 0)
	{
		i = 3;
	}
	else if (ft_strcmp(line, "pb") == 0)
	{
		i = 4;
	}
	else if (ft_strcmp(line, "ra") == 0)
	{
		i = 5;
	}
	else if (ft_strcmp(line, "rb") == 0)
	{
		i = 6;
	}
	else if (ft_strcmp(line, "rra") == 0)
	{
		i = 7;
	}
	else if (ft_strcmp(line, "rrb") == 0)
	{
		i = 8;
	}
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_check_instructions("sa", stack);
		i = 2;
	}
	else if (ft_strcmp(line, "rr") == 0)
	{
		ft_check_instructions("ra", stack);
		i = 6;
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_check_instructions("rra", stack);
		i = 8;
	}
	else
	{
		return (0);
	}
	ft_realloc_string(stack, i);
	return (1);
}

int	ft_realloc_string(t_stack *stack, int i)
{
	int		j;
	char	*tmp;

	tmp = NULL;
	j = 0;
	if (stack->instructions != NULL && ft_strlen(stack->instructions))
	{
		tmp = ft_strnew(ft_strlen(stack->instructions) + 1);
		while (stack->instructions[j])
		{
			tmp[j] = stack->instructions[j];
			j++;
		}
		free(stack->instructions);
	}
	else
	{
		tmp = ft_strnew(1);
	}
	tmp[j] = (i < 10 && i >= 0) ? '0' + i : '\n';
	j = 0;
	stack->instructions = ft_strnew(ft_strlen(tmp));
	while (tmp[j])
	{
		stack->instructions[j] = tmp[j];
		j++;
	}
	free(tmp);
	return (1);
}

int	ft_instructions(t_stack *stack)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_check_instructions(line, stack) == 0)
		{
			return (0);
		}
		free(line);
	}
	return (1);
}

int	ft_test_instructions(t_stack *stack)
{
	int		cursor;
	p_fct	*ft_execute_instructions;

	cursor = 0;
	ft_execute_instructions = ft_set_exec_fct();
	while (stack->instructions != NULL && stack->instructions[cursor])
	{
		ft_execute_instructions[stack->instructions[cursor] - '0' - 1](stack);
		cursor++;
	}
	if (ft_check_stack_order(stack) == 0)
	{
		ft_putstr("KO\n");
		return (1);
	}
	ft_putstr("OK\n");
	return (1);
}

p_fct	*ft_set_exec_fct(void)
{
	static p_fct	ft_execute_instructions[11] = {&ft_execution_sa,&ft_execution_sb,&ft_execution_pa,&ft_execution_pb,&ft_execution_ra,&ft_execution_rb,&ft_execution_rra,&ft_execution_rrb};

	return (ft_execute_instructions);
}

int		ft_optimize_instructions(char **result)
{
	int i;

	i = 0;
	while ((*result)[i])
	{
		if ((*result)[i] == '\n')
			i++;
		if ((*result)[i] == '5' && ft_suppress_ra(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*ra*/
		if ((*result)[i] == '7' && ft_suppress_rra(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*rra*/
		if ((*result)[i] == '6' && ft_suppress_rb(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*rb*/
		if ((*result)[i] == '8' && ft_suppress_rrb(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*rrb*/
		if ((*result)[i] == '1' && ft_suppress_sa(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*sa*/
		if ((*result)[i] == '2' && ft_suppress_sb(result, i) == 1)
		{
			// ft_putstr("aaa\n");
			ft_optimize_instructions(result);
		}/*sb*/
		i++;
	}
	return (1);
}
