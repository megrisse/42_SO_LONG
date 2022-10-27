/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megrisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:17:39 by megrisse          #+#    #+#             */
/*   Updated: 2021/11/26 18:44:27 by megrisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	while (s[x] && s[x] == c)
		x++;
	if (s[x] && s[x] != c)
	{
		count++;
		x++;
	}
	while (s[x])
	{
		if (s[x - 1] == c && s[x] != c)
			count++;
		x++;
	}
	return (count);
}

static char	**ft_free(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	int		len;
	char	**split;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	i = 0;
	x = 0;
	while (i < ft_wordcount(s, c))
	{
		while (s[x] == c)
			x++;
		len = ft_word_len(s + x, c);
		split[i] = ft_substr(s, x, len);
		if (split[i] == NULL)
			return (ft_free(split, i));
		x += len;
		i++;
	}
	split[i] = 0;
	return (split);
}
