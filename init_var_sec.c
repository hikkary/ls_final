/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_sec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 23:22:43 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/23 17:58:59 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_var(t_file **pivot, t_file **end, t_file **cur, t_file **head)
{
	*pivot = *end;
	*cur = *head;
}

void	init_var2(t_file **prev, t_file **tail, t_file **pivot)
{
	*prev = NULL;
	*tail = *pivot;
}
