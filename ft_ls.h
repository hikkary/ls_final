/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 22:05:11 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 22:21:55 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <pwd.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"
# define RESET "\033[0m"

typedef struct dirent		t_dir;
typedef struct passwd		t_passwd;
typedef struct group		t_group;
typedef struct stat			t_stat;
typedef struct timespec		t_timespec;
typedef struct				s_optlst
{
	char					**elem;
	char					**files;
	char					**invalid;
	char					**recu;
	int						l;
	int						ur;
	int						a;
	int						r;
	int						t;
	int						g;
	int						tot;
	int						ct;
	int						ce;
	int						cf;
	int						cd;
	int						ba;
}							t_optlst;

typedef struct				s_file
{
	char					type;
	char					*rights;
	char					xattributes;
	int						links;
	char					*uname;
	char					*gname;
	long					size;
	t_timespec				laccess;
	t_timespec				ldatamod;
	t_timespec				lstatch;
	t_timespec				birthtime;
	char					*dname;
	char					*lnpath;
	char					*l;
	int						minor;
	int						major;
	int						blocks;
	int						denied;
	struct s_file			*next;
}							t_file;
int							check_bzero(char *argv);
int							ft_is_dir(char *path);
int							ft_is_file(char *filename);
int							ft_dircheck(char *argv, int j, t_optlst *opts,
	char type);
int							ft_filecheck(char *argv, int f, t_optlst *opts);
t_optlst					*init_opts(int argc, t_optlst *opts);
t_optlst					*ft_double_moin(t_optlst *o, char **av);
t_optlst					*check_opts(char **av, t_optlst *o);
t_optlst					*ft_link(char **argv, t_optlst *opts);
t_optlst					*sort_args(char **argv, t_optlst *opts);
char						ft_gettype(t_stat filestats);
char						*ft_getrights(t_stat filestats);
void						ft_puttime(t_stat filestats, t_file **file);
void						ft_fillinfo(t_stat filestats, t_file **file);
void						ft_fill_major(t_stat filestats, t_file **file);
t_stat						ft_stat(char *path, char *filename, t_file **file);
t_file						*ft_putinfo(t_file *file, char *filename,
	char *dirname);
void						init_list(t_file **list);
t_file						*new_link(t_file *new_list, t_file *before);
void						ft_free_list(t_file *begin_list);
int							ft_lst_len(t_file *begin_list);
t_file						*get_tail(t_file *cur);
t_file						*lswa(t_file *before, DIR *directory,
	t_dir *dirstruct, char *dirname);
t_file						*lsa(t_file *before, DIR *directory,
	t_dir *dirstruct, char *dirname);
int							ft_count_block(t_file *myfile);
void						ft_print_block(t_optlst *opts, char *dirname,
	t_file *myfile);
t_file						*ft_ls(char *dirname, DIR *directory,
	t_optlst *opts);
char						*color(t_file *file);
void						ft_print_p1_color(t_file *file);
void						ft_printinfo_color(t_file *file, t_optlst *opts);
void						ft_what_print(t_file *file, t_optlst *opts);
void						ft_simpleprint(t_file *file, t_optlst *opts);
void						ft_print_p1(t_file *file);
void						ft_print_time(t_file *file, t_optlst *opts);
void						ft_printinfo(t_file *file, t_optlst *opts);
char						**ft_sorted_tab_rev(char **tab);
int							ft_timecmp(char *str1, char *str2);
char						**ft_sorted_tab_time(char **tab);
t_file						*ft_sort_opts(t_optlst *opts, t_file *myfile);
void						rem_null(t_file **myfile);
t_file						*ft_sort_opts_files(t_optlst *opts, t_file *myfile);
t_file						*ft_sort_reverse(t_file *begin);
void						ft_putnstrcolor(int size, char *str, char *color);
int							ft_cnumber(int n);
void						ft_putnnbr(int size, int nbr);
void						init_var(t_file **pivot, t_file **end,
	t_file **cur, t_file **head);
void						init_var2(t_file **prev, t_file **tail,
	t_file **pivot);
int							main(int argc, char **argv);
t_optlst					*ft_all_parse(int argc, char **argv,
	t_optlst *opts);
void						ft_fill_opt(char c, t_optlst *opts);
void						ft_illegal_options(char c);
char						ft_is_option(char c);
int							ft_checkfor_opt(char *arg, t_optlst *opts);
int							check_azero(char *argv, int end_opt,
	t_optlst *opts);
void						ft_no_directory(char *str);
void						ft_permission_denied(char *str);
void						print_dir(t_file *myfile, t_optlst *opts);
void						print_elem(t_optlst *opts, t_file *myfile,
	DIR *directory, int i);
void						no_arg(t_optlst *opts, t_file *myfile,
	DIR *directory);
void						init_recu(t_file **myfile, char **tmp,
	t_file **begin);
void						ft_print_dir_and_tmp(t_file **newfile,
	t_optlst *opts, char **tmp);
void						ft_strclr_and_myfile_next(char **tmp,
	t_file **myfile);
int							ft_dot_c(t_file *file);
void						ft_lsrecu(DIR *directory, t_optlst *opts,
	t_file *myfile, char *path);
void						ft_print_ol(char *tmp);
void						ft_print_denied_recu(t_file *myfile, char *tmp);
void						ft_print_dir_name(char *opts);
void						ft_arginv(t_optlst *opts);
void						ft_argfiles(t_optlst *opts, t_file *myfile,
	t_file *before, t_file *tmp);
void						print_invalid(t_optlst *opts);
t_optlst					*check_err_file(t_optlst *opts);
void						ft_arginv(t_optlst *opts);
void						ft_argfiles(t_optlst *opts, t_file *myfile,
	t_file *before, t_file *tmp);
void						print_invalid(t_optlst *opts);
int							c_d_ps(t_file *cur, t_file *pivot);
int							c_d_pn(t_file *cur, t_file *pivot);
int							c_g_pn(t_file *cur, t_file *pivot);
int							c_l_pn(t_file *cur, t_file *pivot);
int							c_e_ps(t_file *cur, t_file *pivot);
t_file						*partition(t_file *head, t_file *end,
	t_file **nhead, t_file **n_end);
t_file						*quick_recur(t_file *head, t_file *end);
void						quick_sort_name(t_file **head);
void						n_head_n_end(t_file ***nhead, t_file ***n_end,
	t_file **tail, t_file **pivot);
t_file						*partition_sec(t_file *head, t_file *end,
	t_file **nhead, t_file **n_end);
t_file						*quick_recur_sec(t_file *head, t_file *end);
void						quick_sort_sec(t_file **head);
void						part_else(t_file **prev, t_file **cur,
	t_file **tail, t_file **tmp);
void						if_part(t_file **nhead, t_file **cur,
	t_file **prev);
t_optlst					*arg_n(t_optlst *opts);
#endif
