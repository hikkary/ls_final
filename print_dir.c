/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:56:21 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:00:37 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_dir(t_file *myfile, t_optlst *opts)
{
	if (myfile->dname == NULL)
		return ;
	while (myfile != NULL)
	{
		ft_what_print(myfile, opts);
		myfile = myfile->next;
	}
}

void	print_elem(t_optlst *opts, t_file *myfile, DIR *directory, int i)
{
	char	*path;

	while (opts->elem[++i])
	{
		if (ft_tablen(opts->elem) >= 2 || opts->files[0] || opts->invalid[0])
			ft_print_dir_name(opts->elem[i]);
		if (ft_is_dir(opts->elem[i]) == 1)
		{
			ft_permission_denied(opts->elem[i]);
		}
		else
		{
			directory = opendir(opts->elem[i]);
			myfile = ft_ls(opts->elem[i], directory, opts);
			print_dir(myfile, opts);
			if (ft_tablen(opts->elem) >= 2)
				ft_putchar('\n');
			if (opts->ur == 1)
			{
				path = ft_strjoin(opts->elem[i], "/");
				ft_lsrecu(directory, opts, myfile, path);
			}
		}
	}
}

void	no_arg(t_optlst *opts, t_file *myfile, DIR *directory)
{
	char	*path;
	t_file	*begin;

	directory = opendir(".");
	myfile = ft_ls(".", directory, opts);
	begin = myfile;
	print_dir(myfile, opts);
	if (opts->ur == 1)
	{
		path = ft_strjoin(".", "/");
		ft_lsrecu(directory, opts, myfile, path);
	}
}
