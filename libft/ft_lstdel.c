/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:05:18 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 19:05:19 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cnt;

	while (*alst)
	{
		cnt = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = cnt;
	}
}
