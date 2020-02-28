/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:15:53 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/25 15:05:50 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

int	skip_ws(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' '
			|| line[i] == '\t'
			|| line[i] == '\v'
			// || line[i] == '\n'
			)
			i++;
	return (i);
}

int		get_name_len(char *name)
{
	int i;

	i = 0;
	while (name[i] && name[i] != '"')
		i++;
	return (i);
}

char	*get_chmp_name(char *s)
{
	int		name_len;
	char	*name;

	s += skip_ws(s);
	name_len = 0;
	if (s[0] == '"')
	{
		if ((name_len = get_name_len(++s)) > PROG_NAME_LENGTH)
			return (NULL);
		name = ft_strsub(s, 0, name_len);
		return (name);
	}
	return (NULL);
}

char	*get_chmp_desc(char *s)
{
	int		desc_len;
	char	*desc;

	s += skip_ws(s);
	desc_len = 0;
	if (s[0] == '"')
	{
		if ((desc_len = get_name_len(++s)) > COMMENT_LENGTH)
			return (NULL);
		desc = ft_strsub(s, 0, desc_len);
		return (desc);
	}
	else
		return (NULL);
}

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
	while (s[i])
	{
		// ft_printf("%c", s[i]);
		if (s[i] == ':')
			return (i);
		i++;
	}
	return (0);
}

// int		add_op_to_label(int fd)

int		get_label(char *s, int fd, t_ass_env *env, int x)
{
	int i;
	t_label	*new;

	i = 0;
	// ft_printf("yes1");
	// new->label = ft_strsub(s, 0, x);
	// new->op = NULL;
	// new->next = NULL;
	return (1);
}

void	parse(char *s, t_ass_env *aenv, int fd)
{
	int l;
	
	if (!ft_strncmp(s, NAME_CMD_STRING, 5))
	{
		if (!(aenv->champ.prog_name = get_chmp_name(s + 5)))
			ft_printf("oh no");
	}
	else if (!ft_strncmp(s, COMMENT_CMD_STRING, 8)) 
	{
		if (!(aenv->champ.prog_desc = get_chmp_desc(s + 8)))
			ft_printf("oh no");
	}
	else if ((l = is_label(s)) > 0)
	{
		printf("%.*s\n", l, s);
		if (!get_label(s, fd, aenv, l))
			ft_printf("oh no");
	}
	// else
	// 	ft_putendl("no");
}

int	ass(char *filename, t_ass_env *aenv)
{
	int			fd;
	int			sz;
	char		*line;
	char		*tmp;

	if (!(fd = open(filename, O_RDONLY)))
		return (0);
	while ((sz = get_next_line(fd, &line)) > 0)
	{
		tmp += skip_ws(tmp);
		if (line[0] == '#')
		{
			ft_strdel(&line);
			continue ;
		}
		tmp = line;
		// ft_putendl(line);
		parse(tmp + skip_ws(tmp), aenv, fd);
		ft_strdel(&line);
	}
	return (1);
}

void	init_env(t_ass_env *env)
{
	env->champ.prog_name = NULL;
	env->champ.prog_desc = NULL;
	env->labels = NULL;
	env->op = NULL;
}

int	main(int argc, char **argv)
{
	t_ass_env	aenv;

	init_env(&aenv);
	if (argc > 1 && !ass(argv[1], &aenv))
	{
		ft_printf("no");
	}
	ft_printf("\n%s", aenv.champ.prog_name);
	ft_printf("\n%s", aenv.champ.prog_desc);
	return (0);
}