/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:15:55 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 14:56:53 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int		ft_ok_ko(t_stack *stack)
{
	if (ft_check_stack_order(stack) == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (1);
}

t_fct	*ft_set_exec_fct(void)
{
	static t_fct	ft_execute_instructions[8] =
	{&ft_execution_sa, &ft_execution_sb, &ft_execution_pa, &ft_execution_pb,
		&ft_execution_ra, &ft_execution_rb, &ft_execution_rra,
		&ft_execution_rrb};

	return (ft_execute_instructions);
}

int		ft_realloc_string(t_stack *stack, int i)
{
	int		j;
	char	*tmp;

	tmp = NULL;
	j = 0;
	if (stack->instructions != NULL && ft_strlen(stack->instructions))
	{
		if (!(tmp = ft_strnew(ft_strlen(stack->instructions) + 1)))
		{
			ft_free_instructions(stack);
			ft_error(stack);
			return (0);
		}
		while (stack->instructions[j])
		{
			tmp[j] = stack->instructions[j];
			j++;
		}
	}
	else
		tmp = ft_strnew(1);
	ft_free_instructions(stack);
	ft_realloc_string_bis(stack, &tmp, &j, &i);
	return (1);
}

int		ft_realloc_string_bis(t_stack *stack, char **tmp, int *j, int *i)
{
	(*tmp)[j[0]] = (i[0] < 10 && i[0] >= 0) ? '0' + i[0] : '\n';
	j[0] = 0;
	if (!(stack->instructions = ft_strnew(ft_strlen(*tmp))))
		return (ft_error(stack));
	while ((*tmp)[j[0]])
	{
		stack->instructions[j[0]] = (*tmp)[j[0]];
		j[0]++;
	}
	free(*tmp);
	*tmp = NULL;
	return (1);
}
