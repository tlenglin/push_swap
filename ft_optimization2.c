/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:13:43 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/08 21:20:00 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_suppress_sa(char **str, int i)
{
	int j;

	j = i + 1;
	while ((*str)[j])
	{
		if ((*str)[j] == '2')
		{
			(*str)[j] = ',';
			(*str)[i + 1] = '0';
			(*str)[i] = '0';
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '5' || (*str)[j] == '7' || (*str)[j] == ',' ||
		(*str)[j] == '.' || (*str)[j] == ':')
			return (0);
		j++;
	}
	return (0);
}

int	ft_suppress_sb(char **str, int i)
{
	int j;

	j = i + 1;
	while ((*str)[j])
	{
		if ((*str)[j] == '1')
		{
			(*str)[j] = ',';
			(*str)[i] = '0';
			(*str)[i + 1] = '0';
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' ||
		(*str)[j] == '6' || (*str)[j] == '8' || (*str)[j] == ',' ||
		(*str)[j] == '.' || (*str)[j] == ':')
			return (0);
		j++;
	}
	return (0);
}
