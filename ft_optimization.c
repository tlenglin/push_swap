/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:15:37 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 11:25:51 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_suppress_ra(char **str, int i)
{
	int j;

	j = i;
	while ((*str)[++j])
	{
		if ((*str)[j] == '7')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			return (1);
		}
		else if ((*str)[j] == '6')
		{
			(*str)[j] = '.';
			(*str)[i + 1] = '0';
			(*str)[i] = '0';
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '5' || (*str)[j] == ',' || (*str)[j] == '.' ||
		(*str)[j] == ':')
			return (0);
	}
	return (0);
}

int	ft_suppress_rra(char **str, int i)
{
	int j;

	j = i;
	while ((*str)[++j])
	{
		if ((*str)[j] == '5')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			return (1);
		}
		else if ((*str)[j] == '8')
		{
			(*str)[j] = ':';
			(*str)[i + 1] = '0';
			(*str)[i] = '0';
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '7' || (*str)[j] == ',' || (*str)[j] == '.' ||
		(*str)[j] == ':')
			return (0);
	}
	return (0);
}

int	ft_suppress_rb(char **str, int i)
{
	int j;

	j = i;
	while ((*str)[++j])
	{
		if ((*str)[j] == '8')
		{
			(*str)[i] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			(*str)[j] = '0';
			return (1);
		}
		else if ((*str)[j] == '5')
		{
			(*str)[j] = '.';
			(*str)[i + 1] = '0';
			(*str)[i] = '0';
		}
		else if ((*str)[j] == '2' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '6' || (*str)[j] == ',' || (*str)[j] == '.' ||
		(*str)[j] == ':')
			return (0);
	}
	return (0);
}

int	ft_suppress_rrb(char **str, int i)
{
	int j;

	j = i;
	while ((*str)[++j])
	{
		if ((*str)[j] == '6')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			return (1);
		}
		else if ((*str)[j] == '7')
		{
			(*str)[j] = ':';
			(*str)[i + 1] = '0';
			(*str)[i] = '0';
		}
		else if ((*str)[j] == '2' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '8' || (*str)[j] == ',' || (*str)[j] == '.' ||
		(*str)[j] == ':')
			return (0);
	}
	return (0);
}
