/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_dircheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:46:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:47:54 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_is_dir(char *path)
{
	if (opendir(path) != NULL)
		return (0);
	else
		return (1);
}

int			ft_is_file(char *filename)
{
	struct stat	st;

	return (stat(filename, &st) == 0);
}

t_optlst	*arg_n(t_optlst *opts)
{
	opts->elem[opts->cd] = NULL;
	opts->files[opts->cf] = NULL;
	opts->invalid[opts->ce] = NULL;
	return (opts);
}

int			ft_dircheck(char *argv, int j, t_optlst *opts, char type)
{
	if (ft_is_dir(argv) == 0 || type == 'd')
	{
		opts->elem[j] = ft_strdup(argv);
		return (1);
	}
	return (0);
}

int			ft_filecheck(char *argv, int f, t_optlst *opts)
{
	if (ft_is_file(argv) == 1)
	{
		opts->files[f] = ft_strdup(argv);
		return (1);
	}
	return (0);
}
