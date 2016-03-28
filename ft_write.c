/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:51:55 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:51:56 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnstrcolor(int size, char *str, char *color)
{
	int	len;

	len = ft_strlen(str);
	while (size - len >= 0)
	{
		ft_putchar(' ');
		size--;
	}
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(RESET);
}

int		ft_cnumber(int n)
{
	int			count;

	count = 0;
	if (n == 0)
		return (count + 1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	ft_putnnbr(int size, int nbr)
{
	int	len;

	len = ft_cnumber(nbr);
	while (size - len >= 0)
	{
		ft_putchar(' ');
		size--;
	}
	ft_putnbr(nbr);
}
