/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:16:57 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:16:58 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_strnew(len);
	if (!s || !str)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
