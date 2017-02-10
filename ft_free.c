/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:55:46 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 14:58:36 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	ft_free_instructions(t_stack *stack)
{
	if (stack->instructions != NULL)
	{
		free(stack->instructions);
		stack->instructions = NULL;
	}
	return (1);
}
