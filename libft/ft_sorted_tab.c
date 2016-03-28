/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:09:53 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:09:53 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sorted_tab(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	len = ft_tablen(tab);
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < len)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = ft_strdup(tab[j - 1]);
				tab[j - 1] = ft_strdup(tab[j]);
				tab[j] = ft_strdup(tmp);
			}
			j++;
		}
		i++;
	}
	return (tab);
}
