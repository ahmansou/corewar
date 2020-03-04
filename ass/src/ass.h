/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:13:36 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/04 15:27:31 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASS_H
# define ASS_H

# define BUFF_SIZE 1
# define FD_LIMIT 4864

# include "../../libft/libft.h"
# include "../../ft_printf/src/ft_printf.h"
# include "../../op.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>


typedef	struct		s_lines
{
	char			*line;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_op
{	
	char			*name;
	char			binary;
	char			arg[3];
	int				code;
	int				cycle;
	char			*desc;
	char			carry;
	char			octcode;
	// t_regs			regs;
	char			*regs[REG_NUMBER];
	int				r;
	int				r1;
	int				r2;
	struct s_op		*next;
}					t_op;

typedef struct		s_ch
{
	char			*prog_name;
	char			*prog_desc;
}					t_ch;

typedef struct		s_label
{
	char			*label;
	struct s_op		*op;
	struct s_label	*next;
}					t_label;


typedef struct		s_ass_env
{
	struct s_op		*op;
	struct s_label	*labels;
	t_lines			*lines;
	struct s_ch		champ;
}					t_ass_env;

typedef struct		s_op_types
{
	int 			opss[16];
	int				(*t[16])(t_op *op, char **split);
}					t_op_types;

// t_regs				regs;

// char *reg[REG_NUMBER];

// int	get_regid(char *s);

t_op_types			get_o_types(void);
int					_live(t_op *op, char **split);
int					_ld(t_op *op, char **split);
int					_st(t_op *op, char **split);
int					_add(t_op *op, char **split);
int					_sub(t_op *op, char **split);

//gnl
int 				get_lines(char *filename, t_ass_env *env);

//ass
int					ass(char *filename, t_ass_env *env);

//msc
int					skip_ws(char *line);
const t_op			*get_op_tab(void);

//parser
void				parse(t_lines *ltmp, t_ass_env *env);

//parsmsc
int					get_name_len(char *name);
char				*get_chmp_name(char *s);
char				*get_chmp_desc(char *s);

//label
int					is_label(char *s);
// int					get_label(char *s, t_ass_env *env, int x);
int					get_label(t_lines *ltmp, t_ass_env *env, int x);

//ops
int					get_ops(t_ass_env *env, t_lines *ltmp, t_label *clabel,
						int x);

char				**ft_split_whitespaces(char *str);

#endif
