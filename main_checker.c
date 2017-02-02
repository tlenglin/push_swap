/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:45:52 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/30 14:29:04 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (ft_read_arg(argc, argv, &stack) == 0)
		return (0);
	if (ft_instructions(&stack) == 0)
		return (0);
	if (ft_test_instructions(&stack) == 0)
		return (0);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}
