/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 21:20:19 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/29 14:52:23 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

static char	*ft_join(char *str, const char *buf)
{
	char	*res;

	res = ft_strjoin(str, buf);
	free(str);
	return (res);
}

static int	get_next_line(const int fd, char **line)
{
	char		*str;
	char		buf[2];
	size_t		size;

	if (read(fd, buf, 0) < 0)
		return (-1);
	ft_bzero(buf, 2);
	str = ft_strnew(0);
	while ((size = read(fd, buf, 1)) > 0)
	{
		if (*buf == '\n')
			break ;
		str = ft_join(str, buf);
	}
	if (!*buf)
	{
		free(str);
		return (0);
	}
	*line = str;
	return (1);
}

static int	insert_line(char *line, t_ass_env *env)
{
	t_lines	*new;
	t_lines	*tmp;

	if (!(new = (t_lines*)malloc(sizeof(t_lines))))
		return (0);
	if (!(new->line = ft_strdup(line)))
		return (0);
	new->next = NULL;
	tmp = env->lines;
	if (env->lines == NULL)
	{
		env->lines = new;
		return (1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

int 		get_lines(char *filename, t_ass_env *env)
{
	char	*line;
	int		sz;
	int		fd;

	if (!(fd = open(filename, O_RDONLY)))
		return (0);
	while ((sz = get_next_line(fd, &line)))
	{
		if (!insert_line(line, env))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	if (sz < 0)
		return (0);
	return (1);
}
