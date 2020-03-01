/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:46:28 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/01 13:58:18 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

static void	init_env(t_ass_env *env)
{
	env->champ.prog_name = NULL;
	env->champ.prog_desc = NULL;
	env->labels = NULL;
	env->op = NULL;
}

int			main(int argc, char **argv)
{
	t_ass_env	env;
	t_label		*ltmp;
	t_op		*otmp;

	init_env(&env);
	if (argc > 1 && !ass(argv[1], &env))
	{
		ft_printf("no");
	}
	ft_printf("\n%s", env.champ.prog_name);
	ft_printf("\n%s\n", env.champ.prog_desc);
	ltmp = env.labels;
	while (ltmp)
	{
		ft_printf("%s : {", ltmp->label);
		otmp = ltmp->op;
		while (otmp)
		{
			ft_printf("|%s| ", otmp->name);
			otmp = otmp->next;
		}
		ltmp = ltmp->next;
		ft_putendl("}");
	}
	return (0);
}
