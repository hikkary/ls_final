/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:49:04 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:49:06 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_sort_reverse(t_file *begin)
{
	t_file	*prev;
	t_file	*curr;
	t_file	*temp;

	curr = begin->next;
	prev = begin;
	while (begin->next)
		begin = begin->next;
	prev->next = NULL;
	while (curr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return (begin);
}
