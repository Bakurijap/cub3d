/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:29:48 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:57:11 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen((char *)s) - 1;
	if ((char )c == 0)
		return (&((char *)s)[ft_strlen(s)]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(int c, char **v)
{
	(void) c;
	printf("%s\n", ft_strrchr(v[1], atoi(v[2])));
	return (0);
}
*/
