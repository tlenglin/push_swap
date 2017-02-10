/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:42:36 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 14:57:07 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_check_instructions(char *line, t_stack *stack)
{
	int		i;

	i = ft_check_instructions_bis(line, stack);
	if (ft_strcmp(line, "rr") == 0)
	{
		ft_check_instructions("ra", stack);
		i = 6;
	}
	else if (ft_strcmp(line, "rrr") == 0)
	{
		ft_check_instructions("rra", stack);
		i = 8;
	}
	if (i == 0)
	{
		ft_free_instructions(stack);
		return (ft_error(stack));
	}
	if (ft_realloc_string(stack, i) == 0)
		return (0);
	return (1);
}

int		ft_check_instructions_bis(char *line, t_stack *stack)
{
	int i;

	i = 0;
	if (ft_strcmp(line, "sa") == 0)
		i = 1;
	else if (ft_strcmp(line, "sb") == 0)
		i = 2;
	else if (ft_strcmp(line, "pa") == 0)
		i = 3;
	else if (ft_strcmp(line, "pb") == 0)
		i = 4;
	else if (ft_strcmp(line, "ra") == 0)
		i = 5;
	else if (ft_strcmp(line, "rb") == 0)
		i = 6;
	else if (ft_strcmp(line, "rra") == 0)
		i = 7;
	else if (ft_strcmp(line, "rrb") == 0)
		i = 8;
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_check_instructions("sa", stack);
		i = 2;
	}
	return (i);
}

int		ft_instructions(t_stack *stack)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_check_instructions(line, stack) == 0)
		{
			free(line);
			line = NULL;
			return (0);
		}
		free(line);
		line = NULL;
	}
	return (1);
}

int		ft_test_instructions(t_stack *stack)
{
	int		cursor;
	t_fct	*ft_execute_instructions;
	char	*str;

	cursor = 0;
	str = NULL;
	ft_execute_instructions = ft_set_exec_fct();
	if (stack->instructions == NULL)
		return (ft_ok_ko(stack));
	if (!(str = ft_strdup(stack->instructions)))
	{
		free(stack->instructions);
		return (ft_error(stack));
	}
	while (str != NULL && str[cursor])
	{
		ft_execute_instructions[str[cursor] - '0' - 1](stack);
		cursor++;
	}
	free(str);
	str = NULL;
	ft_ok_ko(stack);
	return (1);
}

int		ft_optimize_instructions(char **result)
{
	int i;

	i = 0;
	while ((*result)[i])
	{
		if ((*result)[i] == '5' && ft_suppress_ra(result, i) == 1)
			ft_optimize_instructions(result);
		else if ((*result)[i] == '7' && ft_suppress_rra(result, i) == 1)
			ft_optimize_instructions(result);
		else if ((*result)[i] == '6' && ft_suppress_rb(result, i) == 1)
			ft_optimize_instructions(result);
		else if ((*result)[i] == '8' && ft_suppress_rrb(result, i) == 1)
			ft_optimize_instructions(result);
		else if ((*result)[i] == '1' && ft_suppress_sa(result, i) == 1)
			ft_optimize_instructions(result);
		else if ((*result)[i] == '2' && ft_suppress_sb(result, i) == 1)
			ft_optimize_instructions(result);
		i++;
	}
	return (1);
}
