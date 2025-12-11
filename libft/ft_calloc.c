/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:37:23 by yabou-da          #+#    #+#             */
/*   Updated: 2024/12/16 10:38:06 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t size_of_element)
{
	void	*tab;

	if (num_elements * size_of_element > 2147483647)
		return (NULL);
	if (num_elements == 0 || size_of_element == 0)
		return (malloc(0));
	tab = malloc(num_elements * size_of_element);
	if (!tab)
		return (NULL);
	ft_bzero(tab, num_elements * size_of_element);
	return (tab);
}
/*
int	main(int c, char **v)
{
	(void) c;
	char * s = ft_calloc(atoi(v[1]), atoi(v[2]));
	printf("%s\n", s);
	return (0);
}
*/
