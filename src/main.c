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
	print_line_list(data.line);

	parse_data(&data);
	check_map_characters(&data);
	check_player_count(&data);
	check_map_closed(&data);
    validate_textures(&data);

	printf("NO texture path: %s\n", data.elements.no);
	printf("SO texture path: %s\n", data.elements.so);
	printf("WE texture path: %s\n", data.elements.we);
	printf("EA texture path: %s\n", data.elements.ea);
	printf("Floor color: 0x%06X\n", data.elements.f_color);
	printf("Ceiling color: 0x%06X\n", data.elements.c_color);
	
	// check_map_characters(&data);
	// check_player_count(&data);
	// check_map_closed(&data);

	free_data(&data);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_data	data;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <map.cub>\n", argv[0]);
// 		return (1);
// 	}
//     check_filetype(argv[1]);
// 	init_data(&data);
// 	data.line = file_to_line_list(argv[1]);
// 	parse_data(&data);
//     validate_textures(&data);

// 	printf("NO texture path: %s\n", data.elements.no);
// 	printf("SO texture path: %s\n", data.elements.so);
// 	printf("WE texture path: %s\n", data.elements.we);
// 	printf("EA texture path: %s\n", data.elements.ea);
// 	printf("Floor color: 0x%06X\n", data.elements.f_color);
// 	printf("Ceiling color: 0x%06X\n", data.elements.c_color);

// 	free_data(&data);
// 	// also free allocated strings in elements here to avoid leaks

// 	return (0);
// }

// void	*mlx;
	// void	*win;

	// Very Good but we will use this after the parsing (it can contain leaks if my memory is good)

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 800, 600, "cub3d");

	// mlx_hook(win, 17, 0, close_window, NULL); // red X button
	// mlx_loop(mlx);