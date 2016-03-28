/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:58:28 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:03:14 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_recu(t_file **myfile, char **tmp, t_file **begin)
{
	*tmp = NULL;
	*begin = *myfile;
	if ((*myfile)->dname == NULL)
		*myfile = NULL;
}

void	ft_print_dir_and_tmp(t_file **newfile, t_optlst *opts, char **tmp)
{
	print_dir(*newfile, opts);
	*tmp = ft_strjoin(*tmp, "/");
}

void	ft_strclr_and_myfile_next(char **tmp, t_file **myfile)
{
	ft_strclr(*tmp);
	*myfile = (*myfile)->next;
}

int		ft_dot_c(t_file *file)
{
	if (ft_strcmp(file->dname, ".") != 0 && ft_strcmp(file->dname, "..") != 0)
		return (1);
	return (0);
}

void	ft_lsrecu(DIR *directory, t_optlst *opts, t_file *myfile, char *path)
{
	DIR		*newdir;
	t_file	*newfile;
	t_file	*begin;
	char	*tmp;

	init_recu(&myfile, &tmp, &begin);
	while (myfile != NULL)
	{
		tmp = ft_strjoin(path, myfile->dname);
		if (myfile->type == 'd' && ft_dot_c(myfile) == 1 && myfile->type != 'l')
		{
			if ((newdir = opendir(tmp)))
			{
				newfile = ft_ls(tmp, newdir, opts);
				if (opts->l == 0)
					ft_print_ol(tmp);
				ft_print_dir_and_tmp(&newfile, opts, &tmp);
				ft_lsrecu(directory, opts, newfile, tmp);
			}
			else
				ft_print_denied_recu(myfile, tmp);
		}
		ft_strclr_and_myfile_next(&tmp, &myfile);
	}
	ft_free_list(begin);
}
