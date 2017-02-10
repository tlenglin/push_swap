/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 10:32:07 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/09 15:27:18 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_get_min(int *tab, int length_s, int length)
{
	int	i;
	int min;
	int i_min;

	i = length - length_s;
	min = tab[i];
	i_min = i;
	while (i < length)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

int	ft_get_max(int *tab, int length_s, int length)
{
	int	i;
	int max;
	int i_max;

	i = length - length_s;
	max = tab[i];
	i_max = i;
	while (i < length)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			i_max = i;
		}
		i++;
	}
	return (i_max);
}

int	ft_get_base_cut(int length_s)
{
	int i;

	i = 6;
	while ((i * 2) < length_s)
	{
		i = i * 2;
	}
	return (i);
}

int	ft_get_value(int *tab, int length_s, int length, int cut)
{
	int	i;
	int j;
	int count;
	int	tab_bis[length_s];

	i = length - length_s;
	while (i < length)
	{
		j = length - length_s;
		count = 0;
		while (j < length)
		{
			if (tab[i] < tab[j])
				count++;
			j++;
		}
		tab_bis[length_s - 1 - count] = tab[i];
		i++;
	}
	return (tab_bis[cut - 1]);
}

int	ft_get_medium(int *tab, int length_s, int length, int len)
{
	int	i;
	int j;
	int count;
	int	tab_bis[len];

	i = length - length_s;
	while (i < (length - length_s + len))
	{
		j = length - length_s;
		count = 0;
		while (j < (length - length_s + len))
		{
			if (tab[i] < tab[j])
				count++;
			j++;
		}
		tab_bis[len - 1 - count] = tab[i];
		i++;
	}
	return (tab_bis[len / 2]);
}
