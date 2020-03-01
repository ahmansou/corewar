/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:04:10 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/29 15:43:52 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

int		is_label_char(char c)
{
	int i;

	i = -1;
	while (LABEL_CHARS[++i])
		if (LABEL_CHARS[i] == c)
			return (1);
	return (0);
}

int		is_label(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != LABEL_CHAR)
	{
		if (!is_label_char(s[i]))
			return (0);
		i++;
	}
	if (s[i] == LABEL_CHAR)
		return (i);
	return (0);
}

int		get_label(t_lines *ltmp, t_ass_env *env, int x)
{
	t_label	*new;
	t_label	*tmp;

	if (!(new = (t_label*)ft_memalloc(sizeof(t_label))))
		return (0);
	new->label = ft_strsub(ltmp->line, 0, x);
	new->op = NULL;
	new->next = NULL;
	if (!env->labels)
		env->labels = new;
	else
	{
		tmp = env->labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (get_ops(env, ltmp, new, x));
}
