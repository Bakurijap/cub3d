/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabou-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:57 by yabou-da          #+#    #+#             */
/*   Updated: 2025/11/27 18:46:19 by yabou-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(int c, char **v)
{
	check_name(c, v);
	// void	*mlx;
	// void	*win;

	// Very Good but we will use this after the parsing (it can contain leaks if my memory is good)

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 800, 600, "cub3d");

	// mlx_hook(win, 17, 0, close_window, NULL); // red X button
	// mlx_loop(mlx);
	return (0);
}
