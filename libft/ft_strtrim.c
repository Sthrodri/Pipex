/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:06:30 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 15:06:36 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_new;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1) + 1;
	while (s1_len && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	s1_new = (char *) malloc((s1_len + 1) * sizeof(char));
	if (!s1_new)
		return (NULL);
	ft_strlcpy(s1_new, s1, s1_len + 1);
	return (s1_new);
}
