/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:50:12 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/03 15:18:55 by bjaparid         ###   ########.fr       */
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

static char **allocation(char const *s, char c)
{
    int i = 0;
    int n = 0;
    char **split;

    while (s[i])
    {
        if ((i == 0 || s[i - 1] == c) && (s[i] != c))
            n++;
        i++;
    }

    split = malloc((n + 1) * sizeof(char *));
    if (!split)
        return NULL;
    return split;
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
        if ((k == 0 || s[k - 1] == c) && s[k] != c)
        {
            mot = append(s, c, &k);
            if (!mot)
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