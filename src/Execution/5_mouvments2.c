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

void	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.plane_x * data->player.move_speed;
	new_y = data->player.pos_y - data->player.plane_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
}

void	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.plane_x * data->player.move_speed;
	new_y = data->player.pos_y + data->player.plane_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
}
