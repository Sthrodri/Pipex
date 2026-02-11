/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:30:27 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:33:39 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_l;
	size_t	src_l;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size <= dst_l)
		return (src_l + size);
	while (src[i] && (dst_l + 1) < size)
		dst[dst_l++] = src[i++];
	dst[dst_l] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
