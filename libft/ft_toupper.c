/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:16:13 by yabou-da          #+#    #+#             */
/*   Updated: 2024/11/11 16:23:35 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_toupper(int c)
{
	if (c < 123 && c > 96)
		return (c - 32);
	return (c);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(int c, char **v)
{
	(void) c;
	printf("%d\n", toupper(atoi(v[1])));
	return (0);
}*/
