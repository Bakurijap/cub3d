/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:25:12 by yabou-da          #+#    #+#             */
/*   Updated: 2024/12/01 17:31:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((len(src) + 1) * sizeof(char));
	if (!dest || !src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(int c, char **v)
{
	int	i;

	i = 1;
	while (c > i)
	{
		printf("%s\n",ft_strdup(v[i]));
		i++;
	}
	return(0);
}
*/