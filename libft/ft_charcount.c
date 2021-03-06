/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:02:10 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:02:11 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charcount(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			nb++;
		i++;
	}
	return (nb);
}
