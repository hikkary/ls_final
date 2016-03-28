/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:46:12 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:46:13 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fill_opt(char c, t_optlst *opts)
{
	if (c == 'R')
		opts->ur = 1;
	else if (c == 'l')
		opts->l = 1;
	else if (c == 'a')
		opts->a = 1;
	else if (c == 'r')
		opts->r = 1;
	else if (c == 't')
		opts->t = 1;
	else if (c == 'G')
		opts->g = 1;
}

void	ft_illegal_options(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putendl_fd("\nusage: ls [-RalrtG] [file ...]", 2);
}

char	ft_is_option(char c)
{
	if (c == 'R' || c == 'l' || c == 'a' || c == 'r' || c == 't' || c == 'G')
		return (1);
	return (0);
}

int		ft_checkfor_opt(char *arg, t_optlst *opts)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (ft_is_option(arg[i]) == 0)
		{
			ft_illegal_options(arg[i]);
			return (0);
		}
		ft_fill_opt(arg[i], opts);
		i++;
	}
	return (1);
}

int		check_azero(char *argv, int end_opt, t_optlst *opts)
{
	if (argv[0] == '-' && argv[1] == '-' && !argv[2])
	{
		return (0);
	}
	if (argv[0] == '-' && !argv[1])
	{
		ft_no_directory("-");
		return (1);
	}
	if (argv[0] == '-' && end_opt == 0)
	{
		end_opt = (argv[1] == '\0' ? 1 : (0));
		if (ft_checkfor_opt(argv, opts) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
