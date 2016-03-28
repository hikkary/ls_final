/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:53:18 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 16:54:22 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_no_directory(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

void	ft_permission_denied(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Permission denied\n", 2);
}
