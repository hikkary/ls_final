/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:45:57 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:45:58 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_sort_opts(t_optlst *opts, t_file *myfile)
{
	quick_sort_name(&myfile);
	if (opts->t == 1)
		quick_sort_sec(&myfile);
	if (opts->r == 1)
		myfile = ft_sort_reverse(myfile);
	return (myfile);
}

void	rem_null(t_file **myfile)
{
	t_file **tmp;

	tmp = NULL;
	(*tmp) = (*myfile);
	while (*myfile)
	{
		if (*tmp == NULL)
		{
			free(*tmp);
			break ;
		}
		(*tmp) = (*myfile)->next;
	}
}

t_file	*ft_sort_opts_files(t_optlst *opts, t_file *myfile)
{
	quick_sort_name(&myfile);
	if (opts->t == 1)
		quick_sort_sec(&myfile);
	if (opts->r == 1)
		myfile = ft_sort_reverse(myfile);
	return (myfile);
}
