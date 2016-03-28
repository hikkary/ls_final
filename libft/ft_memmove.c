/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:06:38 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:06:39 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (src_cpy <= dst_cpy)
	{
		dst_cpy = dst_cpy + (len - 1);
		src_cpy = src_cpy + (len - 1);
		while (len--)
			*dst_cpy-- = *src_cpy--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
