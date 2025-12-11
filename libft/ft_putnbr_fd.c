/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:12:24 by yabou-da          #+#    #+#             */
/*   Updated: 2024/12/04 15:38:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	d;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		d = n % 10 + '0';
		ft_putchar_fd(d, fd);
	}
}
/*
#include <stdlib.h>
int	main(int c, char **v)
{
	(void) c;
	ft_putnbr_fd(atoi(v[1]), atoi(v[2]));
	ft_putchar_fd('\n', atoi(v[2]));
	return (0);
}
*/