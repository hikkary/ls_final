/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:51:29 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 16:52:01 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_sorted_tab_rev(char **tab)
{
	int		i;
	int		j;
	int		len;
	int		fin;
	char	*tmp;

	len = ft_tablen(tab);
	fin = len - 1;
	i = 0;
	j = 0;
	while (i < len / 2)
	{
		tmp = ft_strdup(tab[j]);
		tab[j] = ft_strdup(tab[fin]);
		tab[fin] = ft_strdup(tmp);
		j++;
		fin--;
		i++;
	}
	return (tab);
}

int		ft_timecmp(char *str1, char *str2)
{
	t_stat		t1;
	t_stat		t2;
	t_timespec	ts1;
	t_timespec	ts2;

	lstat(str1, &t1);
	lstat(str2, &t2);
	ts1 = t1.st_mtimespec;
	ts2 = t2.st_mtimespec;
	if (ts1.tv_sec == ts2.tv_sec)
	{
		if (ts1.tv_nsec == ts2.tv_nsec)
			return (0);
		else if (ts1.tv_nsec < ts2.tv_nsec)
			return (-1);
		else if (ts1.tv_nsec > ts2.tv_nsec)
			return (1);
	}
	else if (ts1.tv_sec < ts2.tv_sec)
		return (-1);
	else if (ts1.tv_sec > ts2.tv_sec)
		return (1);
	return (0);
}

char	**ft_sorted_tab_time(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	len = ft_tablen(tab);
	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < len)
		{
			if (ft_timecmp(tab[j - 1], tab[j]) == -1)
			{
				tmp = ft_strdup(tab[j - 1]);
				tab[j - 1] = ft_strdup(tab[j]);
				tab[j] = ft_strdup(tmp);
			}
			j++;
		}
		i++;
	}
	return (tab);
}
