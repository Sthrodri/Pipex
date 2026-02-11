/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:46:49 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 15:11:00 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		s_new = malloc((len + 1) * sizeof(char));
	else
		s_new = malloc((s_len - start + 1) * sizeof(char));
	if (s_new)
	{
		if (len > s_len + 1)
			len = s_len + 1;
		ft_strlcpy(s_new, (s + start), (len + 1));
	}
	else
		return (NULL);
	return (s_new);
}
