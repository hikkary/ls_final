/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:47:22 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:47:24 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_gettype(t_stat filestats)
{
	if (S_ISFIFO(filestats.st_mode))
		return ('p');
	else if (S_ISCHR(filestats.st_mode))
		return ('c');
	else if (S_ISDIR(filestats.st_mode))
		return ('d');
	else if (S_ISBLK(filestats.st_mode))
		return ('b');
	else if (S_ISREG(filestats.st_mode))
		return ('-');
	else if (S_ISLNK(filestats.st_mode))
		return ('l');
	else if (filestats.st_mode & S_IFSOCK)
		return ('s');
	else
		return ('-');
}

char	*ft_getrights(t_stat filestats)
{
	char	*rights;

	rights = ft_strnew(10);
	rights[0] = (filestats.st_mode & S_IRUSR) ? 'r' : '-';
	rights[1] = (filestats.st_mode & S_IWUSR) ? 'w' : '-';
	rights[2] = (filestats.st_mode & S_IXUSR) ? 'x' : '-';
	rights[3] = (filestats.st_mode & S_IRGRP) ? 'r' : '-';
	rights[4] = (filestats.st_mode & S_IWGRP) ? 'w' : '-';
	rights[5] = (filestats.st_mode & S_IXGRP) ? 'x' : '-';
	rights[6] = (filestats.st_mode & S_IROTH) ? 'r' : '-';
	rights[7] = (filestats.st_mode & S_IWOTH) ? 'w' : '-';
	rights[8] = (filestats.st_mode & S_IXOTH) ? 'x' : '-';
	rights[9] = '\0';
	if (rights[2] != 'x')
		rights[2] = (filestats.st_mode & S_ISUID) ? 'S' : '-';
	if (rights[5] != 'x')
		rights[5] = (filestats.st_mode & S_ISGID) ? 'S' : '-';
	if (rights[8] != 'x')
		rights[8] = (filestats.st_mode & S_ISVTX) ? 'T' : '-';
	return (rights);
}
