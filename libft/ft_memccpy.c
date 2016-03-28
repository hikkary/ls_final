/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:06:07 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:06:08 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_cpy;
	unsigned char	*dst_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		if (src_cpy[i] == (unsigned char)c)
			return (dst_cpy + i + 1);
		i++;
	}
	return (NULL);
}
