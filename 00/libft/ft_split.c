/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamagis <tyamagis@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:45:53 by tyamagis          #+#    #+#             */
/*   Updated: 2020/11/30 14:10:24 by tyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ctidx(char const *s, char c)
{
	size_t	idx;

	idx = 0;
	while (*s)
	{
		if (*s != c && ((*(s + 1) == c) || (!*(s + 1))))
			idx++;
		s++;
	}
	return (idx + 1);
}

static size_t	ctwds(char const *s, char c)
{
	size_t	wds;

	wds = 0;
	while (*s && *s != c)
	{
		wds++;
		s++;
	}
	return (wds + 1);
}

static void		spfree(char **sp, int i)
{
	while (i-- > 0)
		free(sp[i]);
	free(sp);
}

static int		splt(char **sp, char const *s, char c)
{
	int i;
	int j;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			if (!(sp[i] = (char *)malloc(ctwds(s, c))))
			{
				spfree(sp, i);
				return (0);
			}
		}
		j = 0;
		while (*s && *s != c)
			sp[i][j++] = *s++;
		if (j)
			sp[i++][j] = '\0';
	}
	sp[i] = (NULL);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char	**sp;

	if (!(sp = (char **)malloc(sizeof(char *) * ctidx(s, c))))
		return (NULL);
	if (!(splt(sp, s, c)))
		return (NULL);
	return (sp);
}
