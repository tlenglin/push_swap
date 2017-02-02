/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:15:37 by tlenglin          #+#    #+#             */
/*   Updated: 2017/01/31 14:26:43 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_suppress_ra(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '7')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '5' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}

int	ft_suppress_rra(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '5')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '7' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}

int	ft_suppress_rb(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '8')
		{
			(*str)[i] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			(*str)[j] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '2' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '6' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}

int	ft_suppress_rrb(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '6')
		{
			(*str)[i] = '0';
			(*str)[j] = '0';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '2' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '8' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}

int	ft_suppress_sa(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '2')
		{
			(*str)[i] = ',';
			(*str)[j + 1] = '0';
			(*str)[j] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '5' || (*str)[j] == '7' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}

int	ft_suppress_sb(char **str, int i)
{
	int j;

	j = i + 1;
	// ft_putstr("bbb\n");
	while ((*str)[j])
	{
		if ((*str)[j] == '1')
		{
			(*str)[i] = ',';
			(*str)[i + 1] = '0';
			(*str)[j + 1] = '0';
			// ft_putnbr(i);

			// ft_putnbr(j);
			return (1);
		}
		else if ((*str)[j] == '1' || (*str)[j] == '3' || (*str)[j] == '4' || (*str)[j] == '6' || (*str)[j] == '8' || (*str)[j] == ',' || (*str)[j] == '.' || (*str)[j] == ':')
		{
			return (0);
		}
		j++;
	}
	return (0);
}
