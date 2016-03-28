/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_files.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:42:50 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:36:07 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_arginv(t_optlst *opts)
{
	int i;

	i = 0;
	while (i < ft_tablen(opts->invalid))
	{
		ft_no_directory(opts->invalid[i]);
		i++;
	}
}

void		ft_argfiles(t_optlst *opts, t_file *myfile, t_file *before,
	t_file *tmp)
{
	int		i;

	init_list(&tmp);
	init_list(&before);
	init_list(&myfile);
	before = myfile;
	i = 0;
	while (i < ft_tablen(opts->files))
	{
		before = ft_putinfo(before, opts->files[i], ".");
		tmp = before;
		before = new_link(before->next, before);
		i++;
	}
	tmp->next = NULL;
	myfile = ft_sort_opts_files(opts, myfile);
	print_dir(myfile, opts);
	if (opts->elem[0])
		ft_putchar('\n');
	ft_free_list(myfile);
}

void		print_invalid(t_optlst *opts)
{
	opts->invalid = ft_sorted_tab(opts->invalid);
	ft_arginv(opts);
}

t_optlst	*check_err_file(t_optlst *opts)
{
	if (opts->ba != 0)
	{
		if (opts->elem[0])
		{
			opts->elem = ft_sorted_tab(opts->elem);
			if (opts->t == 1)
				opts->elem = ft_sorted_tab_time(opts->elem);
			if (opts->r == 1)
				opts->elem = ft_sorted_tab_rev(opts->elem);
		}
		if (opts->invalid[0])
			print_invalid(opts);
		if (opts->files[0])
		{
			opts->files = ft_sorted_tab(opts->files);
			if (opts->r == 1)
				opts->files = ft_sorted_tab_rev(opts->files);
			if (opts->t == 1)
				opts->files = ft_sorted_tab_time(opts->files);
			ft_argfiles(opts, NULL, NULL, NULL);
		}
	}
	return (opts);
}
