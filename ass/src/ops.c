/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:24:46 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/02 11:59:46 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

int	get_args_live(t_op *op, char **split)
{
	if (op->code == 1)
	{
		if (!split[0] || !split[1] || (split[2] && split[2][0] != '#'))
			return (0);
		if (split[1][0] == '%')
			op->arg[1] == T_DIR;
	}
	return (1);
}

int		get_op_type(char *op)
{
	const t_op	*opt;
	int			i;
	
	opt = get_op_tab();
	i = -1;
	while (++i < 17)
		if (!ft_strcmp(op, opt[i].name))
			return (opt[i].code);
	return (0);
}

t_op	*new_op(char *op)
{
	t_op		*new;
	int			code;
	char		**split;
	
	if (!(new = (t_op*)ft_memalloc(sizeof(t_op))))
		return (0);
	if (!(split = ft_split_whitespaces(op)) || !split[0])
		return (0);
	new->name = ft_strdup(split[0]);
	new->code = get_op_type(split[0]);
	if (!get_args_live(new, split))
		return (NULL);
	return (new);
}

int		add_op(t_ass_env *env, t_label *clabel, t_op *op)
{
	t_op	*otmp;

	if (!op)
		return (0);
	if (!clabel->op)
		clabel->op = op;
	else
	{
		otmp = clabel->op;
		while (otmp->next)
			otmp = otmp->next;
		otmp->next = op;
	}
	return (1);
}

int		get_ops(t_ass_env *env, t_lines *ltmp, t_label *clabel, int x)
{
	ltmp->line += skip_ws(ltmp->line) + x + 1;
	while (ltmp)
	{
		ltmp->line += skip_ws(ltmp->line);
		if (ltmp->line[0] == '#' || ltmp->line[0] == ' ' ||
			ltmp->line[0] == '\t' || ltmp->line[0] == '\n')
		{
			ltmp = ltmp->next;
			continue ;
		}
		if (ltmp->line[0] != '\0')
			if (!add_op(env, clabel, new_op(ltmp->line)))
				return (0);
		if (ltmp->next && is_label(ltmp->next->line))
			break ;
		ltmp = ltmp->next;
	}
	return (1);
}
