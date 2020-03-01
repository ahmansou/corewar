/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:24:46 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/01 15:03:59 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

t_op	*new_op(char *op)
{
	t_op		*new;
	const t_op	*opt;
	int			code;
	char		**split;
	
	if (!(new = (t_op*)ft_memalloc(sizeof(t_op))))
		return (0);
	if (!(split = ft_split_whitespaces(op)) || !split[0])
		return (0);
	new->name = ft_strdup(split[0]);
	opt = get_op_tab();
	return (new);
}

int		add_op(t_ass_env *env, t_label *clabel, t_op *op)
{
	t_op	*otmp;

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
