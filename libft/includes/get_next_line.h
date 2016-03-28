/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <zkerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 23:40:42 by zkerkeb           #+#    #+#             */
/*   Updated: 2016/03/27 23:40:43 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 3000

typedef	struct	s_struct
{
	char		*buf;
	char		*buf2;
}				t_struct;

int				get_next_line(int const fd, char **line);

#endif
