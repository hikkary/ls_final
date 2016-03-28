# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/27 22:26:59 by zkerkeb           #+#    #+#              #
#    Updated: 2016/03/27 23:10:41 by zkerkeb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = 			arg_checks.c				\
				file_dircheck.c				\
				ft_all_parse.c				\
				ft_getinfos.c				\
				ft_infos.c					\
				ft_list.c					\
				ft_list2.c					\
				ft_ls.c						\
				ft_print_color.c			\
				ft_print_list.c				\
				ft_sort.c					\
				ft_sort_dir.c				\
				ft_sort_opt.c				\
				ft_write.c					\
				init_var_sec.c				\
				main.c						\
				opts_check.c				\
				opts_check2.c				\
				print_dir.c					\
				print_dir2.c				\
				print_dir3.c				\
				print_error_and_files.c		\
				quick_sec_useful.c			\
				quick_sort_name.c			\
				quick_sort_sec.c			\
				quick_sort_useful.c			\

DOTO	=		$(SRC:.c=.o)

FLAGS	= -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(DOTO)
	make -C libft
	gcc $(FLAGS) -lft -L ./libft -o $(NAME) $(DOTO)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	make -C libft/ fclean
	rm -rf $(DOTO)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
