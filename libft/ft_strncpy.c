/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:10:27 by mjarraya          #+#    #+#             */
/*   Updated: 2016/03/27 19:15:28 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*s;

	s = dst;
	while (*src != '\0' && n > 0)
	{
		*s++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*s++ = '\0';
		n--;
	}
	return (dst);
}
