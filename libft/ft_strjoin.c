/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:31:16 by yabou-da          #+#    #+#             */
/*   Updated: 2024/12/04 15:34:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fuuuuuuuusion;

	fuuuuuuuusion = malloc ((len(s1) + len(s2) + 1) * sizeof(char));
	if (!fuuuuuuuusion)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		fuuuuuuuusion[j++] = s1[i++];
	i = 0;
	while (s2[i])
		fuuuuuuuusion[j++] = s2[i++];
	fuuuuuuuusion[j] = '\0';
	return (fuuuuuuuusion);
}
/*
int	main(int c, char **v)
{
	(void) c;
	printf("%s\n", ft_strjoin(v[1], v[2]));
	return (0);
}
*/