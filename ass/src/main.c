/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:46:28 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/03 16:12:35 by ahmansou         ###   ########.fr       */
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

void print_reg(t_op *op)
{
	int i;
	
	i = 1;
	while (i <= REG_NUMBER)
	{
		if (op->r == i)
		// if (op->regs[i])
			ft_printf("R%d = %d, ", i, op->regs[i - 1]);
		i++;
	}
}

void print_arg(t_op *op)
{
	int i;

	i = -1;
	while (++i < 3)
		if (op->arg[i])
		{
			if (op->arg[i] == 1)
				ft_putstr("T_REG ");
			else if (op->arg[i] == 2)
				ft_putstr("T_DIR ");
			else if (op->arg[i] == 4)
				ft_putstr("T_IND ");
			else if (op->arg[i] == 8)
				ft_putstr("T_LAB ");
		}
			// ft_printf("%d, ", op->arg[i]);
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
			ft_printf("\n\t%s {", otmp->name);
			ft_putstr("\n\t\tARGS : ");
			print_arg(otmp);
			ft_putstr("\n\t\tREGS : ");
			print_reg(otmp);
			ft_putendl("\n\t}");
			otmp = otmp->next;
		}
		ltmp = ltmp->next;
		ft_putendl("\n}\n");
	}
	return (0);
}
