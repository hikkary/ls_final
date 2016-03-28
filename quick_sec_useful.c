/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sec_useful.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 17:04:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 17:04:45 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				c_d_ps(t_file *cur, t_file *pivot)
{
	if (cur->ldatamod.tv_sec != pivot->ldatamod.tv_sec)
		return (1);
	else
		return (0);
}

int				c_d_pn(t_file *cur, t_file *pivot)
{
	if (cur->ldatamod.tv_nsec != pivot->ldatamod.tv_nsec)
		return (1);
	else
		return (0);
}

int				c_g_pn(t_file *cur, t_file *pivot)
{
	if (cur->ldatamod.tv_nsec > pivot->ldatamod.tv_nsec)
		return (1);
	else
		return (0);
}

int				c_l_pn(t_file *cur, t_file *pivot)
{
	if (cur->ldatamod.tv_nsec < pivot->ldatamod.tv_nsec)
		return (1);
	else
		return (0);
}

int				c_e_ps(t_file *cur, t_file *pivot)
{
	if (cur->ldatamod.tv_sec == pivot->ldatamod.tv_sec)
		return (1);
	else
		return (0);
}
