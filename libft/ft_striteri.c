/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:40:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 20:40:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	fonction(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(int c, char**v)
{
	(void) c;
	ft_striteri(v[1], fonction);
	printf("%s\n", v[1]);
	return (0);
}
*/