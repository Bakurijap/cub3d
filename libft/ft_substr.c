/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:43:08 by marvin            #+#    #+#             */
/*   Updated: 2024/11/24 23:43:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	if (len > - (size_t)start + ft_strlen(s))
		len = - (size_t)start + ft_strlen(s);
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (i < len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
/*
int	main(int c, char **v)
{
	char *s = ft_substr(v[1], atoi(v[2]), atoi(v[3]));
	(void) c;
	printf("%s\n", s);
	return (0);
}
*/