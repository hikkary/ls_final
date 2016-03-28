/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:10:02 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:10:02 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_swap(char *s1, char *s2)
{
	char	*tmp;
	int		i1;
	int		i2;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	if (i1 > i2)
		tmp = (char *)ft_memalloc(sizeof(char) * (i1 + 1));
	else
		tmp = (char *)ft_memalloc(sizeof(char) * (i2 + 1));
	ft_strcpy(tmp, s1);
	ft_strcpy(s1, s2);
	ft_strcpy(s2, tmp);
	free(tmp);
}
