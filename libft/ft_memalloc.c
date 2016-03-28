/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:06:01 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:06:02 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc((sizeof(*ptr) * size));
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return ((void *)ptr);
}
