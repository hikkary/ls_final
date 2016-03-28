/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:52:07 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:34:16 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_what_print(t_file *file, t_optlst *opts)
{
	if (opts->l == 1 && opts->g == 1)
		ft_printinfo_color(file, opts);
	else if (opts->l == 1)
		ft_printinfo(file, opts);
	else
		ft_simpleprint(file, opts);
}

void	ft_simpleprint(t_file *file, t_optlst *opts)
{
	if (file->denied == 1)
	{
		ft_permission_denied(file->dname);
		return ;
	}
	if (opts->g == 1)
		ft_putnstrcolor(0, file->dname, color(file));
	else
		ft_putstr(file->dname);
	ft_putchar('\n');
}

void	ft_print_p1(t_file *file)
{
	ft_putchar(file->type);
	ft_putstr(file->rights);
	ft_putnnbr(3, file->links);
	ft_putnstrcolor(8, file->uname, WHITE);
	ft_putchar(' ');
	ft_putnstrcolor(10, file->gname, WHITE);
	if (file->type == 'c' || file->type == 'b')
	{
		ft_putnnbr(3, file->major);
		ft_putchar(',');
		ft_putnnbr(3, file->minor);
	}
	else
		ft_putnnbr(8, file->size);
	ft_putchar(' ');
}

void	ft_print_time(t_file *file, t_optlst *opts)
{
	if (opts->t == 0 && ((file->ldatamod.tv_sec <= (time(NULL) + 3600) &&
	(file->ldatamod.tv_sec + 15778800) >= time(NULL))))
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 12));
	else if (opts->t == 0)
	{
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 7));
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[19], 5));
	}
	if (opts->t == 1 && ((file->ldatamod.tv_sec <= (time(NULL) + 3600) &&
		(file->ldatamod.tv_sec + 15778800) >= time(NULL))))
	{
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 12));
	}
	else if (opts->t == 1)
	{
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[4], 7));
		ft_putstr(ft_strndup(&(ctime(&file->ldatamod.tv_sec))[19], 5));
	}
	ft_putchar(' ');
}

void	ft_printinfo(t_file *file, t_optlst *opts)
{
	if (file->denied == 1)
	{
		ft_permission_denied(file->dname);
		return ;
	}
	ft_print_p1(file);
	ft_print_time(file, opts);
	if (file->type == 108)
	{
		ft_putnstrcolor(1, file->dname, WHITE);
		ft_putnstrcolor(1, " -> ", WHITE);
		ft_putnstrcolor(1, file->lnpath, WHITE);
	}
	else
		ft_putnstrcolor(0, file->dname, WHITE);
	ft_putchar('\n');
}
