/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:01:13 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/30 11:22:43 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	t1 = (unsigned char *) s1;
	t2 = (unsigned char *) s2;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}
/*
int	main(int c, char **v)
{
	(void) c;
	char *s1 = v[1];
	char *s2 = v[2];
	printf("%d\n",ft_memcmp(s1, s2, atoi(v[3])));
	return (0);
}*/
