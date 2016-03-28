/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:49:21 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:50:47 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*lswa(t_file *before, DIR *directory, t_dir *dirstruct,
	char *dirname)
{
	t_file	*tmp;

	init_list(&tmp);
	while ((dirstruct = readdir(directory)))
	{
		if (dirstruct->d_name[0] != '.')
		{
			before = ft_putinfo(before, dirstruct->d_name, dirname);
			tmp = before;
			before = new_link(before->next, before);
		}
	}
	tmp->next = NULL;
	return (before);
}

t_file		*lsa(t_file *before, DIR *directory, t_dir *dirstruct,
	char *dirname)
{
	t_file	*tmp;

	init_list(&tmp);
	while ((dirstruct = readdir(directory)))
	{
		before = ft_putinfo(before, dirstruct->d_name, dirname);
		tmp = before;
		before = new_link(before->next, before);
	}
	tmp->next = NULL;
	return (before);
}

int			ft_count_block(t_file *myfile)
{
	t_file	*tmp;
	int		block;

	block = 0;
	tmp = myfile;
	while (tmp)
	{
		block += tmp->blocks;
		tmp = tmp->next;
	}
	return (block);
}

void		ft_print_block(t_optlst *opts, char *dirname, t_file *myfile)
{
	int block;

	block = ft_count_block(myfile);
	if (block < 0)
		block = 0;
	if (opts->l == 1 && opts->ur == 1)
	{
		ft_putchar('\n');
		ft_putstr(dirname);
		ft_putendl(":");
		ft_putstr("total ");
		ft_putnbr(block);
		ft_putchar('\n');
	}
	else if (opts->l == 1 && block != 0)
	{
		ft_putstr("total ");
		ft_putnbr(block);
		ft_putchar('\n');
	}
}

t_file		*ft_ls(char *dirname, DIR *directory, t_optlst *opts)
{
	t_dir	*dirstruct;
	t_file	*myfile;
	t_file	*before;
	t_file	*begin;
	int		block;

	init_list(&before);
	init_list(&begin);
	init_list(&myfile);
	dirstruct = NULL;
	before = myfile;
	block = 0;
	if (opts->a == 0)
		before = lswa(before, directory, dirstruct, dirname);
	else
		before = lsa(before, directory, dirstruct, dirname);
	ft_print_block(opts, dirname, myfile);
	if (myfile->next)
		myfile = ft_sort_opts(opts, myfile);
	begin = myfile;
	closedir(directory);
	return (begin);
}
