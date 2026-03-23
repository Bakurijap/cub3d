/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:57 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 17:29:28 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"
#include "cube3d.h"
#include <stdio.h>

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(int c, char **v)
{
	t_data	data;

	init_data(&data);
	check_file(c, v, &data);
	parse_data(&data);
	check_map_characters(&data);
	check_player_count(&data);
	check_map_closed(&data);
	validate_textures(&data);
	init_player_direction(&data);
	init_mlx(&data);
	init_screen(&data);
	init_textures(&data);
	init_hooks(&data);
	mlx_loop_hook(data.mlx.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx.mlx_ptr);
	free_data(&data);
	return (0);
}
