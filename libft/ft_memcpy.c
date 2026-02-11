/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:09:56 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:24:05 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long int	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < (long int)n)
		*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}
