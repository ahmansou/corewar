/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:15:53 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/02 11:24:52 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

int ass(char *filename, t_ass_env *env)
{
	t_lines	*ltmp;
	char	*tmp;

	if (!get_lines(filename, env))
		return (0);
	ltmp = env->lines;
	while (ltmp)
	{
		tmp += skip_ws(tmp);
		if (ltmp->line[0] == '#')
		{
			ltmp = ltmp->next;
			continue ;
		}
		tmp = ltmp->line;
		parse(ltmp, env);
		ltmp = ltmp->next;
	}
	return (1);
}
