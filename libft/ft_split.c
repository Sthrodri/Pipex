/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:17:14 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:57:09 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_make_split(char const *s, char c, size_t i, char **split)
{
	char	*str;
	size_t	s_start;
	size_t	str_len;

	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			s_start = i;
			while (s[i] && s[i] != c)
				i++;
			str_len = (i - s_start) + 1;
			str = malloc(sizeof(char) * str_len);
			ft_strlcpy(str, &s[s_start], str_len);
			*(char **)(split++) = str;
		}
		if (s[i] && s[i] == c)
			while (s[i] && s[i] == c)
				i++;
	}
	split = NULL;
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			while (*s && *s != c)
				s++;
			words++;
		}
		if (*s && *s == c)
			while (*s && *s == c)
				s++;
	}
	return (words + 1);
}

char	**ft_split(char const *s, char c)
{
	size_t	nodes;
	char	**s_split;

	if (!s)
		return (NULL);
	nodes = ft_count_words(s, c);
	s_split = ft_calloc((nodes), sizeof(char *));
	if (!s_split)
		return (NULL);
	ft_make_split(s, c, 0, s_split);
	return (s_split);
}
