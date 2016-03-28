/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:17:03 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:17:03 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*ptr;

	i = 0;
	k = 0;
	while (s[k] != '\0')
		k++;
	while (s[k] == '\0' || s[k] == ' ' || s[k] == '\t' || s[k] == '\n')
		k--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup(""));
	ptr = ft_strsub(s, i, (k - i + 1));
	return (ptr);
}
