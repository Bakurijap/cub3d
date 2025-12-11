/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:20 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:56:37 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if ((char )c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(int c, char **v)
{
	(void) c;
	printf("%s\n", ft_strchr(v[1], atoi(v[2])));
	return (0);
}*/
