/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:13:13 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/09 14:23:41 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
		p[i++] = 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char **v)
{
	(void) c;
	ft_bzero (v[1], atoi(v[2]));
	printf("%s\n", v[1]);

	int arr[10];
	ft_bzero (arr, sizeof(arr));
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}
*/
