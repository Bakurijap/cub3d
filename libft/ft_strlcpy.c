/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:10:03 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:14:28 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
/*
#include <bsd/string.h>
int	main(int c, char **v)
{
	(void) c;
	ft_strlcpy(v[1], v[2], atoi(v[3]));
	printf("%s\n",v[1]);
	printf("%zu\n", ft_strlcpy(v[1], v[2], atoi(v[3])));
	strlcpy(v[1], v[2], atoi(v[3]));
        printf("%s\n",v[1]);
        printf("%zu\n", strlcpy(v[1], v[2], atoi(v[3])));
	return (0);
}*/
