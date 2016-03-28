/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:46:49 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:46:52 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			main(int argc, char **argv)
{
	t_optlst	*opts;
	DIR			*directory;
	t_file		*myfile;

	myfile = NULL;
	directory = NULL;
	if (!(opts = (t_optlst*)malloc(sizeof(t_optlst))))
		return (1);
	if (argc > 1)
	{
		opts = ft_all_parse(argc, argv, opts);
		check_err_file(opts);
		if (opts->ba == 0)
			no_arg(opts, myfile, directory);
		else if (opts->elem[0])
			print_elem(opts, myfile, directory, -1);
	}
	else
	{
		opts = (t_optlst*)malloc(sizeof(t_optlst));
		opts = init_opts(argc, opts);
		no_arg(opts, myfile, directory);
	}
	return (0);
}

t_optlst	*ft_all_parse(int argc, char **argv, t_optlst *opts)
{
	opts = init_opts(argc, opts);
	opts = check_opts(argv, opts);
	if (opts->ba != 0)
		opts = sort_args(argv, opts);
	return (opts);
}
