/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:22:30 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:25:04 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	new_s = malloc(ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	while (*s)
		new_s[i++] = *s++;
	new_s[i] = '\0';
	return (new_s);
}
