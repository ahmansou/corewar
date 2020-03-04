/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:46:28 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/04 15:18:52 by ahmansou         ###   ########.fr       */
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
	
	ft_printf("\n\t\t\tREGS %d %d %d\n\t\t\t", op->r, op->r1, op->r2);
	i = 1;
	while (i <= REG_NUMBER)
	{
		// if (op->r[0] == i)
		if (op->r == i)
			ft_printf("R%d = %s, ", i, op->regs[i - 1]);
		if (op->r1 == i)
			ft_printf("R%d = %s, ", i, op->regs[i - 1]);
		if (op->r2 == i)
			ft_printf("R%d = %s, ", i, op->regs[i - 1]);
		i++;
	}
}

void print_arg(t_op *op)
{
	int i;

	ft_putstr("\t\tARGS : ");
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
			ft_printf("\n\t%s", otmp->name);
			print_arg(otmp);
			print_reg(otmp);
			ft_putendl("\n");
			otmp = otmp->next;
		}
		ltmp = ltmp->next;
		ft_putendl("\n}\n");
	}
	return (0);
}
