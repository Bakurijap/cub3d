/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:55:57 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/08 15:56:10 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long	puissance10(long n)
{
	long	p;

	p = 0;
	while (n > 9)
	{
		n = n / 10;
		p = p + 1;
	}
	return (p);
}

static long	power(long a, long b)
{
	if (b == 0)
		return (1);
	if (b == 1)
		return (a);
	return (power(a, b - 1) * a);
}

static char	*negatif(long n, long i)
{
	long	p;
	char	*tab;

	n = -n;
	p = puissance10(n);
	tab = malloc((p + 3) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[i++] = '-';
	while (p > -1)
	{
		tab[i++] = (n / power(10, p)) + '0';
		n = n % power(10, p--);
	}
	tab[i] = '\0';
	return (tab);
}

static char	*positif(long n, long i)
{
	long	p;
	char	*tab;

	p = puissance10(n);
	tab = malloc((p + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (p > -1)
	{
		tab[i++] = (n / power(10, p)) + '0';
		n = n % power(10, p--);
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	long		i;

	i = 0;
	if (n < 0)
		return (negatif((long)n, i));
	else
		return (positif((long)n, i));
}
/*
int	main(int c, char **v)
{
	(void)c;
	printf("%s\n", ft_itoa(atoi(v[1])));
	return (0);
}
*/