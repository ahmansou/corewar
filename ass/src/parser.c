/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:01:57 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/29 15:31:47 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

void	parse(t_lines *ltmp, t_ass_env *env)
{
	int l;
	
	ltmp->line += skip_ws(ltmp->line); 
	if (!ft_strncmp(ltmp->line, NAME_CMD_STRING, 5))
	{
		if (!(env->champ.prog_name = get_chmp_name(ltmp->line + 5)))
			ft_printf("oh no");
	}
	else if (!ft_strncmp(ltmp->line, COMMENT_CMD_STRING, 8)) 
	{
		if (!(env->champ.prog_desc = get_chmp_desc(ltmp->line + 8)))
			ft_printf("oh no");
	}
	else if ((l = is_label(ltmp->line)) > 0)
	{
		if (!get_label(ltmp, env, l))
			ft_printf("oh no");
	}
}
