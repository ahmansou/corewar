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
	while (line[i] == ' ' ||
			line[i] == '\t' ||
			line[i] == '\v' ||
			line[i] == '\n')
			i++;
	return (i);
}

// void	parse(char *s, t_ass_env aenv)
// {
// 	if (!ft_strncmp(s, ".name"))
// 	{
// 		ft_print("lala");
// 	}
// }

int	ass(char *filename, t_ass_env aenv)
{
	int			fd;
	int			sz;
	char		*line;
	char		*tmp;
	
	if (!(fd = open(filename, O_RDONLY)))
		return (0);
	while ((sz = get_next_line(fd, &line)) > 0)
	{
		tmp = line;
		tmp += skip_ws(tmp);
		ft_printf("%s\n", tmp);
		ft_strdel(&line);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_ass_env	aenv;

	if (argc > 1 && !ass(argv[1], aenv))
	{
		ft_printf("no");
	}
	return (0);
}