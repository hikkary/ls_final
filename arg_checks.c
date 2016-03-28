/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:46:05 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 15:46:09 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	check_bzero(char *argv)
{
	if (argv[0] == '\0')
	{
		ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
		return (1);
	}
	else
		return (0);
}
