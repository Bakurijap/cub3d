/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:58:58 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 15:27:29 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

static void	init_north(t_data *data)
{
	data->player.dir_x = 0;
	data->player.dir_y = -1;
	data->player.plane_x = 0.66;
	data->player.plane_y = 0;
}

static void	init_south(t_data *data)
{
	data->player.dir_x = 0;
	data->player.dir_y = 1;
	data->player.plane_x = -0.66;
	data->player.plane_y = 0;
}

static void	init_east(t_data *data)
{
	data->player.dir_x = 1;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
}

static void	init_west(t_data *data)
{
	data->player.dir_x = -1;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = -0.66;
}

void	init_player_direction(t_data *data)
{
	if (data->player.start_dir == 'N')
		init_north(data);
	else if (data->player.start_dir == 'S')
		init_south(data);
	else if (data->player.start_dir == 'E')
		init_east(data);
	else if (data->player.start_dir == 'W')
		init_west(data);
	else
		error_and_exit(data, "Invalid player direction");
	data->player.move_speed = 0.05;
	data->player.rot_speed = 0.03;
}