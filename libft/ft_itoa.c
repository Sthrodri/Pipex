/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:34:37 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:57:44 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	n_new;
	int			n_len;
	char		*str;

	n_new = n;
	n_len = ft_intlen(n_new);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n_new < 0)
		n_new = -n_new;
	while (n_len > 0)
	{
		str[--n_len] = n_new % 10 + '0';
		n_new /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
