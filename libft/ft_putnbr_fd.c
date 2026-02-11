/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrodri <sthrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:14:26 by sthrodri          #+#    #+#             */
/*   Updated: 2024/10/24 14:54:36 by sthrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n_new;

	n_new = n;
	if (n_new < 0)
	{
		n_new *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n_new > 9)
		ft_putnbr_fd(n_new / 10, fd);
	ft_putchar_fd(n_new % 10 + '0', fd);
}
