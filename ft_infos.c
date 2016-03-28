/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:48:50 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:48:53 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_puttime(t_stat filestats, t_file **file)
{
	(*file)->laccess = filestats.st_atimespec;
	(*file)->blocks = filestats.st_blocks;
	(*file)->ldatamod = filestats.st_mtimespec;
	(*file)->lstatch = filestats.st_ctimespec;
	(*file)->birthtime = filestats.st_birthtimespec;
}

void	ft_fillinfo(t_stat filestats, t_file **file)
{
	(*file)->type = ft_gettype(filestats);
	(*file)->rights = ft_getrights(filestats);
	(*file)->links = (int)(filestats.st_nlink);
	if (getpwuid(filestats.st_uid))
		(*file)->uname = (getpwuid(filestats.st_uid))->pw_name;
	else
		(*file)->uname = ft_strnew(1);
	if (getgrgid(filestats.st_gid) != NULL)
		(*file)->gname = (getgrgid(filestats.st_gid))->gr_name;
	else
		(*file)->gname = ft_strnew(1);
	if ((*file)->type != 'b' && (*file)->type != 'c')
		(*file)->size = filestats.st_size;
}

void	ft_fill_major(t_stat filestats, t_file **file)
{
	if ((*file)->type == 'c' || (*file)->type == 'b')
	{
		(*file)->major = (int)major(filestats.st_rdev);
		(*file)->minor = (int)minor(filestats.st_rdev);
	}
}

t_stat	ft_stat(char *path, char *filename, t_file **file)
{
	t_stat filestats;

	if ((lstat(path, &filestats)) == -1)
	{
		if ((lstat(filename, &filestats)) == -1)
			(*file)->denied = 1;
	}
	return (filestats);
}

t_file	*ft_putinfo(t_file *file, char *filename, char *dirname)
{
	ssize_t		i;
	t_stat		filestats;
	char		*path;
	char		buf[257];

	path = NULL;
	path = ft_strjoin(dirname, "/");
	path = ft_strjoin(path, filename);
	filestats = ft_stat(path, filename, &file);
	file->lnpath = malloc(ft_strlen(filename) + 1);
	ft_fillinfo(filestats, &file);
	ft_puttime(filestats, &file);
	file->dname = ft_strdup(filename);
	if (file->type == 'l')
	{
		if ((i = readlink(file->dname, buf, sizeof(buf) - 1)) != -1)
			buf[i] = '\0';
		else if ((i = readlink(path, buf, sizeof(buf) - 1)) != -1)
			buf[i] = '\0';
		file->lnpath = ft_strdup(buf);
	}
	ft_fill_major(filestats, &file);
	path = NULL;
	return (file);
}
