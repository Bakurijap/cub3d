/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:24:55 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:27:06 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_tolower(int c)
{
	if (c < 91 && c > 64)
		return (c + 32);
	return (c);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int c, char **v)
{
	(void) c;
	printf("%d\n", tolower(atoi(v[1])));
	return (0);
}*/
