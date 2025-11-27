/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:57:34 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 13:58:23 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*loop(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t	i;

	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (d);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	return (loop(d, s, n));
}
/*
int	main(int c, char **v)
{
	if (c == 4)
	{
		char *dest = v[1];
		char *src = v[2];
		int n = atoi(v[3]);
		char *r = ft_memmove(dest, src, n);
		char *s = ft_memmove(&dest[1], dest, n);
		printf("%s\n", s);
		printf("%s\n", r);
		printf("%s\n",dest);
		printf("%s\n",src);
	}
	return (0);
}
*/