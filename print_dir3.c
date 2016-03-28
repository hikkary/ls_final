/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:00:17 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:03:20 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ol(char *tmp)
{
	ft_putchar('\n');
	ft_putstr(tmp);
	ft_putstr(":");
	ft_putchar('\n');
}

void	ft_print_denied_recu(t_file *myfile, char *tmp)
{
	ft_putchar('\n');
	ft_putstr(tmp);
	ft_putendl(":");
	if (ft_is_dir(myfile->dname) == 1)
		ft_permission_denied(tmp);
	else
		ft_no_directory(myfile->dname);
}

void	ft_print_dir_name(char *opts)
{
	ft_putstr(opts);
	ft_putendl(":");
}
