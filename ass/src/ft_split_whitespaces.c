/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmansou <ahmansou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:45:49 by ahmansou          #+#    #+#             */
/*   Updated: 2020/03/01 14:53:53 by ahmansou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass.h"

static int	word_count(char *str)
{
	int i;
	int wc;
	int is_word;

	i = 0;
	wc = 0;
	is_word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			is_word = 1;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			if (is_word == 1)
				wc++;
			is_word = 0;
			i++;
		}
	}
	return (wc);
}

static int	wlen(char *str, int i)
{
	int lc;

	lc = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
	{
		lc++;
		i++;
	}
	return (lc);
}

char		**ft_split_whitespaces(char *str)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((arr = malloc(sizeof(char*) * (word_count(str) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((arr[j] = malloc(sizeof(char) * wlen(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
				arr[j][k++] = str[i++];
			arr[j++][k] = '\0';
		}
	}
	arr[j] = NULL;
	return (arr);
}
