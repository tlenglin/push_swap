/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 10:28:46 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/02 14:24:54 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char *result1;
	char *result2;
	char *result3;
	char	*result4;

	result1 = NULL;
	result2 = NULL;
	result3 = NULL;
	result4 = NULL;
	ft_launch_algo(argc, argv, 4, &result4);
	// ft_launch_algo(argc, argv, 2, &result2);
	// ft_launch_algo(argc, argv, 3, &result3);
	ft_print_instructions(result4);
	free(result4);
	// if (!result1 || !result2 || !result3)
	// {
	// 	if (result1)
	// 		free(result1);
	// 	if (result2)
	// 		free(result2);
	// 	if (result3)
	// 		free(result3);
	// 	ft_putstr("erreur, result = null\n");
	// 	return (0);
	// }
	// ft_putstr("algo 1 = ");
	// ft_putnbr(ft_strlen(result1) / 2);
	// ft_putstr("\nalgo 2 = ");
	// ft_putnbr(ft_strlen(result2) / 2);
	// ft_putstr("\nalgo 3 = ");
	// ft_putnbr(ft_strlen(result3) / 2);
	// ft_putchar('\n');
	// if (ft_strlen(result1) < ft_strlen(result2))
	// {
	// 	if (ft_strlen(result3) < ft_strlen(result1))
	// 	{
	// 		ft_print_instructions(result3);
	// 	}
	// 	else
	// 	{
	// 		ft_print_instructions(result1);
	// 	}
	// }
	// else
	// {
	// 	if (ft_strlen(result3) < ft_strlen(result2))
	// 	{
	// 		ft_print_instructions(result3);
	// 	}
	// 	else
	// 	{
	// 		ft_print_instructions(result2);
	// 	}
	// }
	// ft_putstr((ft_strlen(result1) < ft_strlen(result2) ? "algo 1 = \n" : "algo 2 = \n"));
	// ft_print_instructions((ft_strlen(result1) < ft_strlen(result2) ? result1 : result2));
	// ft_putstr((ft_strlen(result1) >= ft_strlen(result2) ? "algo 1 = \n" : "algo 2 = \n"));
	// ft_putnbr((ft_strlen(result1) < ft_strlen(result2) ? ft_strlen(result2) : ft_strlen(result1)));
	// free(result1);
	// free(result2);
	// free(result3);
	return (0);
}

int	ft_launch_algo(int argc, char **argv, int nb, char **result)
{
	t_stack	stack;

	if (ft_read_arg(argc, argv, &stack) == 0)
	{
		free(stack.stack_a);
		free(stack.stack_b);
		return (0);
	}
	if (nb == 1)
	{
		ft_sorting_algo1(&stack, 1);
	}
	else if (nb == 2)
	{
		ft_sorting_algo2(&stack, 1);
	}
	else if (nb == 3)
	{
		ft_sorting_algo3(&stack);
	}
	else if (nb == 4)
	{
		ft_fat_algo(&stack);
	}
	if (stack.instructions != NULL)
	{
		*result = ft_strdup(stack.instructions);
		free(stack.instructions);
	}
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}




// int	main(int argc, char **argv)
// {
// 	t_stack	stack1;
// 	t_stack	stack2;
// 	char	*result;
//
// 	result = NULL;
// 	if (ft_read_arg(argc, argv, &stack1) == 0)
// 		return (0);
// 	if (ft_read_arg(argc, argv, &stack2) == 0)
// 		return (0);
// 	if (ft_sorting_algo1(&stack1, 1) == -1)
// 		return (0);
// 	if (stack1.instructions != NULL)
// 	{
// 		result = ft_strdup(stack1.instructions);
// 		ft_putstr("algo 1 = ");
// 		ft_putnbr(ft_strlen(result));
// 		ft_putchar('\n');
// 		free(stack1.instructions);
// 		ft_putstr("aaa\n");
// 	}
// 	if (ft_sorting_algo2(&stack2, 1) == -1)
// 		return (0);
// 	ft_putstr("bbb\n");
// 	if (result == NULL)
// 	{
// 		ft_putstr("algo 222 = ");
// 		// ft_putnbr(ft_strlen(result));
// 		// ft_putchar('\n');
// 		result = ft_strdup(stack2.instructions);
// 	}
// 	else if (stack2.instructions != NULL && ft_strlen(result) > ft_strlen(stack2.instructions))
// 	{
// 		free(result);
// 		result = malloc(1);
// 		result = ft_strdup(stack2.instructions);
// 		ft_putstr("algo 22 = ");
// 		ft_putnbr(ft_strlen(result));
// 		ft_putchar('\n');
// 		free(stack2.instructions);
// 		ft_putstr("rrr\n");
//
// 	}
// 	else if (stack2.instructions != NULL)
// 	{
// 		ft_putstr("algo 2 = ");
// 		ft_putnbr(ft_strlen(stack2.instructions));
// 		ft_putchar('\n');
// 	}
// 	// ft_putstr("rrr\n");
// 	free(stack1.stack_a);
// 	free(stack1.stack_b);
// 	free(stack2.stack_a);
// 	free(stack2.stack_b);
// 	if (result != NULL)
// 		ft_print_instructions(result);
// 	free(result);
// 	return (0);
// }

int	ft_print_instructions(char *result)
{
	int i;

	i = 0;
	ft_optimize_instructions(&result);
	while (result[i])
	{
		// ft_putnbr(result[i]);
		if (result[i] == '1')
			ft_putstr("sa");
		else if (result[i] == '2')
			ft_putstr("sb");
		else if (result[i] == '3')
			ft_putstr("pa");
		else if (result[i] == '4')
			ft_putstr("pb");
		else if (result[i] == '5')
			ft_putstr("ra");
		else if (result[i] == '6')
			ft_putstr("rb");
		else if (result[i] == '7')
			ft_putstr("rra");
		else if (result[i] == '8')
			ft_putstr("rrb");
		else if (result[i] == ',')
			ft_putstr("ss");
		else if (result[i] == '.')
			ft_putstr("rr");
		else if (result[i] == ':')
			ft_putstr("rrr");
		else if (result[i] == '\n')
			ft_putchar('\n');
		i++;
	}
	return (0);
}
