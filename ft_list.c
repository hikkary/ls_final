/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:47:52 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:47:53 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_list(t_file **list)
{
	if (!(*list = (t_file *)malloc(sizeof(t_file))))
		return ;
	(*list)->dname = NULL;
	(*list)->type = 0;
	(*list)->rights = NULL;
	(*list)->xattributes = 0;
	(*list)->links = 0;
	(*list)->uname = NULL;
	(*list)->gname = NULL;
	(*list)->size = 0;
	(*list)->lnpath = NULL;
	(*list)->l = NULL;
	(*list)->minor = 0;
	(*list)->major = 0;
	(*list)->blocks = 0;
	(*list)->denied = 0;
	(*list)->next = NULL;
}

t_file	*new_link(t_file *new_list, t_file *before)
{
	init_list(&new_list);
	before->next = new_list;
	return (new_list);
}

void	ft_free_list(t_file *begin_list)
{
	t_file *tmp;

	while (begin_list->next != NULL)
	{
		tmp = begin_list->next;
		free(begin_list);
		begin_list = tmp;
	}
}

int		ft_lst_len(t_file *begin_list)
{
	int		i;
	t_file	*newlst;

	i = 0;
	if (!begin_list)
		return (0);
	if (begin_list)
	{
		newlst = begin_list;
		if (!newlst->next)
			return (1);
		while (newlst)
		{
			newlst = newlst->next;
			i++;
		}
		return (i);
	}
	return (0);
}
