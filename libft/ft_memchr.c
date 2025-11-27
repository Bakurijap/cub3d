/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:13:00 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 17:22:39 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	uc;

	i = 0;
	s = (unsigned char *)src;
	uc = (unsigned char )c;
	while (i < n)
	{
		if (s[i] == uc)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char **v)
{
	(void) c;
	char * s = ft_memchr(v[1], atoi(v[2]), atoi(v[3]));
	printf("%s\n", s);
	return (0);
}
*/