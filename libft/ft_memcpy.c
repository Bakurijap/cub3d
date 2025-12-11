/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:33:35 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/09 15:56:04 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char **v)
{
	(void) c;
	ft_memcpy (v[1], v[2], atoi(v[3]));
	printf("%s\n", v[1]);

	int arr[10];
	int ar2[10];
	ft_memcpy (arr, ar2, sizeof(arr));
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}*/