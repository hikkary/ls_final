/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:24:23 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 18:58:17 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i])
	{
		s3[k] = s2[i];
		k++;
		i++;
	}
	return (s3);
}
