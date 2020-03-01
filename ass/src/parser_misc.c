/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:06:01 by ahmansou          #+#    #+#             */
/*   Updated: 2020/02/29 15:07:24 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

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
