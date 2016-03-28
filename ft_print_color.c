/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:55:17 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:58:06 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*color(t_file *file)
{
	if (file->type == 'd')
		return (CYAN);
	if (file->type == 'c')
		return (GREEN);
	if (file->type == 'b')
		return (MAGENTA);
	if (file->type == 'p')
		return (BLUE);
	if (file->type == '-')
		return (WHITE);
	if (file->type == 'l')
		return (YELLOW);
	if (file->type == 's')
		return (RED);
	return (WHITE);
}

void	ft_print_p1_color(t_file *file)
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

void	ft_printinfo_color(t_file *file, t_optlst *opts)
{
	if (file->denied == 1)
	{
		ft_permission_denied(file->dname);
		return ;
	}
	ft_print_p1_color(file);
	ft_print_time(file, opts);
	if (file->type == 108)
	{
		ft_putnstrcolor(1, file->dname, RED);
		ft_putnstrcolor(1, " -> ", MAGENTA);
		ft_putnstrcolor(1, file->lnpath, BLUE);
	}
	else
		ft_putnstrcolor(0, file->dname, color(file));
	ft_putchar('\n');
}
