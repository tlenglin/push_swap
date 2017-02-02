/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:53:30 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/02 15:11:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		length;
	int		length_a;
	int		length_b;
	int		iteration_min;
	int		current_iteration;
	char	*instructions;
}				t_stack;

typedef struct	s_algo
{
	int	min;
	int	max;
	int	i;
}				t_algo;

typedef int(*p_fct)(t_stack*);
typedef int(*p_fct_bis)(int, t_stack*);

int	ft_read_arg(int argc, char **argv, t_stack *stack);
int	ft_instructions(t_stack *stack);
int	ft_check_instructions(char *line, t_stack *stack);
int	ft_test_instructions(t_stack *stack);
p_fct	*ft_set_exec_fct(void);
int	ft_execution_sa(t_stack *stack);
int	ft_execution_sb(t_stack *stack);
// int	ft_execution_ss(t_stack *stack);
int	ft_execution_pa(t_stack *stack);
int	ft_execution_pb(t_stack *stack);
int	ft_execution_ra(t_stack *stack);
int	ft_execution_rb(t_stack *stack);
// int	ft_execution_rr(t_stack *stack);
int	ft_execution_rra(t_stack *stack);
int	ft_execution_rrb(t_stack *stack);
// int	ft_execution_rrr(t_stack *stack);
int	ft_check_stack_order(t_stack *stack);
int	ft_check_duplication(t_stack *stack);
int	ft_realloc_string(t_stack *stack, int i);
int	ft_sorting_algo1_a(t_stack *stack);
int	ft_swap_a(t_algo *algo, t_stack *stack);
int	ft_swap_b(t_algo *algo, t_stack *stack);
int	ft_sorting_algo1(t_stack *stack, int nb);
int	ft_pull_up_a(int i, t_stack *stack);
int	ft_pull_up_b(int i, t_stack *stack);
int	ft_pull_up_min_a(t_stack *stack);
int	ft_pull_up_min_b(t_stack *stack);
int	ft_print_instructions(char *result);
int	ft_insert(t_algo *algo, t_stack *stack);
int	ft_sorting_algo2_a_bis(t_algo *algo, t_stack *stack);
int	ft_sorting_algo2_a(t_stack *stack);
int	ft_sorting_algo2(t_stack *stack, int nb);
int	ft_get_min(int	*tab, int length_s, int length);
int	ft_launch_algo(int argc, char **argv, int nb, char **result);
int	ft_sorting_algo3(t_stack *stack);
int	ft_sorting_algo1_b(t_stack *stack);
int	ft_split_stack(t_stack *stack);
int	ft_merge_stack(t_stack *stack);
int	ft_suppress_ra(char **str, int i);
int		ft_optimize_instructions(char **result);
int	ft_suppress_rra(char **str, int i);
int	ft_suppress_rb(char **str, int i);
int	ft_suppress_rrb(char **str, int i);
int	ft_suppress_sa(char **str, int i);
int	ft_suppress_sb(char **str, int i);
int	ft_split_stack_a(t_stack *stack, int len);
int	ft_split_stack_b(t_stack *stack, int len);
int	ft_get_medium(int *tab, int length_s, int length, int len);
int	ft_parse0(int nb, t_stack *stack);
int	ft_parse1(int nb, t_stack *stack);
int	ft_parse2(int nb, t_stack *stack);
int	ft_parse3(int nb, t_stack *stack);
int	ft_parse4(int nb, t_stack *stack);
int	ft_parse5(int nb, t_stack *stack);
int	ft_fat_algo(t_stack *stack);
int ft_here_comes_the_split(t_stack *stack);
int	ft_last_sorting_ever(t_stack *stack);
int	ft_big_fucking_recursive(t_stack *stack, int loop);
int	ft_stupid_function(t_stack *stack);
int	ft_sorting_algo4_a(t_stack *stack);
p_fct_bis	*ft_set_shitty_parsing(void);
int ft_sorting_six_elem(t_stack *stack);
int	ft_sorting_algo4_b(t_stack *stack);
int	ft_second_split_loop(t_stack *stack, int cut);
int	ft_first_split_loop(t_stack *stack);
int	ft_first_split_b(t_stack *stack);
int	ft_first_split_a(t_stack *stack);
int	ft_split_a(t_stack *stack);
int ft_power(int i);
int	ft_get_value(int *tab, int length_s, int length, int cut);
int	ft_get_base_cut(int length_s);
int	ft_get_max(int *tab, int length_s, int length);
int	ft_execution_ss(t_stack *stack);
int	ft_execution_rr(t_stack *stack);
int	ft_execution_rrr(t_stack *stack);
int	ft_ra_sa_rra(t_stack *stack);
int	ft_rb_sb_rrb(t_stack *stack);
int	ft_rr_ss_rrr(t_stack *stack);
int	ft_rb_ss_rrb(t_stack *stack);
int	ft_ra_ss_rra(t_stack *stack);
int	ft_parsing_of_the_real_shit(int *tab, int length_s, int length);



#endif
