/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:59:50 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/09 14:10:26 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char **v)
{
	(void) c;
	ft_memset (v[1], atoi(v[2]), atoi(v[3]));
	printf("%s\n", v[1]);

	int arr[10];
	ft_memset (arr, 0, sizeof(arr));
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}
*/
/*
/explication du code/
- on pose un unsigned char *p car pour modifier byte par byte 
comme le fait memset if faut convertir c en unsigned char
- unsigned char est %256
- size_t i pour comparer avec n pour pouvoir respecter le prototypage
- p = s car modifier void * directement ca marche pas
*/
