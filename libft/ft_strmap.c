/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:13:21 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:13:22 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	if (!s || !f)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = (*f)(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
