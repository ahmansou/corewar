/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:13:36 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/25 15:05:05 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASS_H
# define ASS_H

# define BUFF_SIZE 1
# define FD_LIMIT 4864

# include "../../libft/libft.h"
# include "../../ft_printf/src/ft_printf.h"
// # include "../../op.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

typedef struct	s_op
{
	char		*name;
	int			carry;
	char		*desc;
	
}				t_op;

typedef struct	s_ass_env
{
	struct s_op	op[17];
}				t_ass_env;

int				get_next_line(const int fd, char **line);

#endif