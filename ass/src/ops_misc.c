/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:40:26 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/04 15:28:33 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

char *reg[REG_NUMBER] = {
	"r1",
	"r2",
	"r3",
	"r4",
	"r5",
	"r6",
	"r7",
	"r8",
	"r9",
	"r10",
	"r11",
	"r12",
	"r13",
	"r14",
	"r15",
	"r16"
};

int	get_regid(char *s)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		if (!ft_strcmp(reg[i], s))
			return (i);
		i++;
	}
	return (1);
}

int	_live(t_op *op, char **split)
{
	if (!split[0] || !split[1] ||
		(split[2] && (split[2][0] != '#' && split[2][0] != ';')))
		return (0);
	if (split[1][0] == '%')
	{
		op->arg[1] = T_DIR;
		// op->r[0] = 1;
		op->r = 1;
		op->regs[0] = ft_strdup(split[1] + 1);
	}
	return (1);
}

int	_ld(t_op *op, char **split)
{
	if (!split[0] || !split[1] || !split[2] ||
		(split[2][0] != 'r' && split[2][0] != 'R') || 
		(split[3] && (split[3][0] != '#' && split[3][0] != ';')))
		return (0);
	if (split[1][0] == '%')
		op->arg[1] = T_DIR;
	if (split[2][0] == '%')
		op->arg[2] = T_DIR;
	else if (split[2][0] == 'r')
	{
		// op->r[0] = ft_atoi(split[2] + 1);
		op->r = ft_atoi(split[2] + 1);
		op->arg[2] = T_REG;
		op->regs[get_regid(split[2])] = ft_strdup(split[1] + 1);
	}
	return (1);
}

int	_st(t_op *op, char **split)
{
	if (!split[0] || !split[1] || !split[2] ||
		(split[3] && (split[3][0] != '#' && split[3][0] != ';')))
		return (0);
	op->arg[0] = T_REG;
	if (split[1][0] == '%')
		op->arg[1] = T_DIR;
	else if (split[1][0] == 'r')
	{
		// op->r[0] = ft_atoi(split[1] + 1);
		op->r = ft_atoi(split[1] + 1);
		op->regs[get_regid(split[1])] = ft_strdup(split[2]);
	}
	if (split[2][0] == ':')
	{
		op->arg[1] = T_IND;
		op->regs[get_regid(split[1])] = ft_strdup(split[2]);
	}
	if (split[2][0] == 'r')
	{
		op->arg[2] = T_REG;
		op->r1 = ft_atoi(split[2] + 1);
		op->regs[get_regid(split[2])] = ft_strdup(split[1]);
	}
	return (1);
}

int	_add(t_op *op, char **split)
{
	if (!split[0] || !split[1] || !split[2] || !split[3] ||
		(split[1][0] != 'r' && split[2][0] != 'r' && split[3][0] != 'r' &&
		split[1][0] != 'R' && split[2][0] != 'R' && split[3][0] != 'R') ||
		(split[4] && (split[4][0] != '#' && split[4][0] != ';')))
		return (0);
	op->arg[0] = T_REG;
	op->arg[1] = T_REG;
	op->arg[2] = T_REG;
	op->r = ft_atoi(split[1] + 1);
	op->r1 = ft_atoi(split[2] + 1);
	op->r2 = ft_atoi(split[3] + 1);
	op->regs[get_regid(split[1])] = ft_strdup(split[1]);
	op->regs[get_regid(split[2])] = ft_strdup(split[2]);
	op->regs[get_regid(split[3])] = ft_strdup(split[3]);
	return (1);
}

int	_sub(t_op *op, char **split)
{
	if (!split[0] || !split[1] || !split[2] || !split[3] ||
		(split[1][0] != 'r' && split[2][0] != 'r' && split[3][0] != 'r' &&
		split[1][0] != 'R' && split[2][0] != 'R' && split[3][0] != 'R') ||
		(split[4] && (split[4][0] != '#' && split[4][0] != ';')))
		return (0);
	op->arg[0] = T_REG;
	op->arg[1] = T_REG;
	op->arg[2] = T_REG;
	op->r = ft_atoi(split[1] + 1);
	op->r1 = ft_atoi(split[2] + 1);
	op->r2 = ft_atoi(split[3] + 1);
	op->regs[get_regid(split[1])] = ft_strdup(split[1]);
	op->regs[get_regid(split[2])] = ft_strdup(split[2]);
	op->regs[get_regid(split[3])] = ft_strdup(split[3]);
	return (1);
}
