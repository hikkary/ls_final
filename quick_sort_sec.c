/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 22:15:47 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:12:58 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			n_head_n_end(t_file ***nhead, t_file ***n_end,
	t_file **tail, t_file **pivot)
{
	if ((**nhead) == NULL)
		**nhead = *pivot;
	(**n_end) = *tail;
}

t_file			*partition_sec(t_file *head, t_file *end,
	t_file **nhead, t_file **n_end)
{
	t_file *pivot;
	t_file *prev;
	t_file *cur;
	t_file *tail;
	t_file *tmp;

	init_var(&pivot, &end, &cur, &head);
	init_var2(&prev, &tail, &pivot);
	while (cur != pivot)
	{
		if (c_d_ps(cur, pivot) && cur->ldatamod.tv_sec > pivot->ldatamod.tv_sec)
			if_part(nhead, &cur, &prev);
		else if (cur->ldatamod.tv_sec < pivot->ldatamod.tv_sec)
			part_else(&prev, &cur, &tail, &tmp);
		else if (c_d_pn(cur, pivot) && c_g_pn(cur, pivot))
			if_part(nhead, &cur, &prev);
		else if (c_l_pn(cur, pivot) && c_e_ps(cur, pivot))
			part_else(&prev, &cur, &tail, &tmp);
		else if ((ft_strcmp(cur->dname, pivot->dname) < 0))
			if_part(nhead, &cur, &prev);
		else
			part_else(&prev, &cur, &tail, &tmp);
	}
	n_head_n_end(&nhead, &n_end, &tail, &pivot);
	return (pivot);
}

t_file			*quick_recur_sec(t_file *head, t_file *end)
{
	t_file *nhead;
	t_file *n_end;
	t_file *pivot;
	t_file *tmp;

	nhead = NULL;
	n_end = NULL;
	if (!head || head == end)
		return (head);
	pivot = partition_sec(head, end, &nhead, &n_end);
	if (nhead != pivot)
	{
		tmp = nhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		nhead = quick_recur_sec(nhead, tmp);
		tmp = get_tail(nhead);
		tmp->next = pivot;
	}
	pivot->next = quick_recur_sec(pivot->next, n_end);
	return (nhead);
}

void			quick_sort_sec(t_file **head)
{
	(*head) = quick_recur_sec(*head, get_tail(*head));
	return ;
}
