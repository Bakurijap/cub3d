/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:33:16 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 17:10:58 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	p;

	i = 0;
	n = 0;
	p = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			p = -p;
		i++;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		n = n * 10 + p * (s[i] - 48);
		i++;
	}
	return (n);
}
/*
#include <stdio.h>
int	main(int c, char** v)
{
	(void) c;
	printf("%d\n", ft_atoi(v[1]));
	return (0);
}
*/
