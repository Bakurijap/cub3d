/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:50:12 by yabou-da          #+#    #+#             */
/*   Updated: 2024/12/04 15:36:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*ft_free(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**allocation(char const *s, char c)
{
	int		i;
	int		n;
	char	**split;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((s[i - 1] == c || s[i - 1] == '\0') && (s[i] != c && s[i] != '\0'))
		{
			n++;
			i++;
		}
		else
			i++;
	}
	split = malloc((n + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (split);
}

static char	*append(char const *s, char c, int *k)
{
	int		tamp;
	int		j;
	char	*mot;

	tamp = *k;
	while (s[*k] != c && s[*k] != '\0')
		(*k)++;
	mot = malloc((*k - tamp + 1) * sizeof(char));
	if (!mot)
		return (NULL);
	j = 0;
	while (tamp < *k)
		mot[j++] = s[tamp++];
	mot[j] = '\0';
	return (mot);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	char	**split;
	char	*mot;

	k = 0;
	i = 0;
	split = allocation(s, c);
	if (split == NULL)
		return (NULL);
	while (s[k])
	{
		if ((s[k - 1] == c || k == 0) && (s[k] != c && s[k] != '\0'))
		{
			mot = append(s, c, &k);
			if (mot == NULL)
				return (ft_free(split));
			split[i++] = mot;
		}
		else
			k++;
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(int c, char **v)
{
	int	i;

	(void)c;
	i = 0;
	while (ft_split(v[1], v[2][0])[i] != NULL)
	{
		printf("%s\n", ft_split(v[1], v[2][0])[i]);
		i++;
	}
	return (0);
}
*/