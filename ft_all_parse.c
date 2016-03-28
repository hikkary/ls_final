/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 16:49:15 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 16:49:44 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_optlst	*init_opts(int argc, t_optlst *opts)
{
	if (!(opts->elem = malloc(sizeof(char *) * argc + 1)))
		return (opts);
	if (!(opts->files = malloc(sizeof(char *) * argc + 1)))
		return (opts);
	if (!(opts->invalid = malloc(sizeof(char *) * argc + 1)))
		return (opts);
	opts->ur = 0;
	opts->l = 0;
	opts->a = 0;
	opts->r = 0;
	opts->t = 0;
	opts->tot = 0;
	opts->ct = 1;
	opts->ba = 0;
	opts->cd = 0;
	opts->cf = 0;
	opts->ce = 0;
	opts->g = 0;
	return (opts);
}

t_optlst	*ft_double_moin(t_optlst *o, char **av)
{
	if (av[o->ct][0] == '-' && av[o->ct][1] == '-' && !av[o->ct + 1])
	{
		o->ba = 0;
	}
	else if (av[o->ct][0] == '-' && av[o->ct][1]
	== '-' && av[o->ct + 1])
	{
		o->ba++;
	}
	return (o);
}

t_optlst	*check_opts(char **av, t_optlst *o)
{
	int end_opt;

	end_opt = 0;
	while (av[o->ct])
	{
		if (check_bzero(av[o->ct]) == 1)
			exit(EXIT_FAILURE);
		if (check_azero(av[o->ct], end_opt, o) == 1)
			exit(EXIT_FAILURE);
		if ((av[o->ct][0] != '-' && end_opt != 1) ||
		(av[o->ct][0] == '-' && av[o->ct][1] == '-' && end_opt != 1))
		{
			o->ba = o->ct;
			end_opt = 1;
			o = ft_double_moin(o, av);
			break ;
		}
		o->ct++;
	}
	return (o);
}

t_optlst	*ft_link(char **argv, t_optlst *opts)
{
	opts->files[opts->cf] = ft_strdup(argv[opts->ba]);
	opts->cf++;
	return (opts);
}

t_optlst	*sort_args(char **argv, t_optlst *opts)
{
	t_stat	fstat;
	char	type;

	type = 0;
	while (argv[opts->ba] != NULL)
	{
		lstat(argv[opts->ba], &fstat);
		type = ft_gettype(fstat);
		if (type == 'l' && opts->l == 1 && lstat(argv[opts->ba], &fstat) != -1)
			ft_link(argv, opts);
		else if (ft_dircheck(argv[opts->ba], opts->cd, opts, type) == 1 &&
		lstat(argv[opts->ba], &fstat) != -1)
			opts->cd++;
		else if (ft_filecheck(argv[opts->ba], opts->cf, opts) == 1)
			opts->cf++;
		else
		{
			opts->invalid[opts->ce] = ft_strdup(argv[opts->ba]);
			opts->ce++;
		}
		opts->ba++;
	}
	opts = arg_n(opts);
	return (opts);
}
