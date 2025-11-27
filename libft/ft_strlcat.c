/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:13:46 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:15:03 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	s;

	i = 0;
	l = len(dest);
	s = len((char *)src);
	if (size <= l)
		return (size + s);
	while (src[i] && size >= l && i < size - l - 1)
	{
		dest[i + l] = src[i];
		i++;
	}
	dest[i + l] = '\0';
	return (s + l);
}
/*
int	main(int c, char **v)
{
	(void) c;
	printf("%zu\n", ft_strlcat(v[1], v[2], atoi(v[3])));
	printf("%s\n",v[1]);
}*/
