/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_useful.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:09:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:12:30 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		part_else(t_file **prev, t_file **cur,
	t_file **tail, t_file **tmp)
{
	if (*prev)
		(*prev)->next = (*cur)->next;
	*tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = *cur;
	*tail = *cur;
	*cur = *tmp;
}

void		if_part(t_file **nhead, t_file **cur, t_file **prev)
{
	if ((*nhead) == NULL)
		(*nhead) = *cur;
	*prev = *cur;
	(*cur) = (*cur)->next;
}
