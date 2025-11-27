/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2025/11/27 18:53:22 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	check_name(int c, char **v)
{
	int	len;

	if (c != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(1);
	}
	len = ft_strlen(v[1]);
	// i dont handle when a file is just named '.cub'
	if (ft_strncmp(".cub", &v[1][len - 4], 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension (expected .cub)\n", 2);
		exit(1);
	}
}

// void	open_test(char *map)
// {

// }