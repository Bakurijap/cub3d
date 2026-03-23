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

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * data->player.move_speed;
	new_y = data->player.pos_y + data->player.dir_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * data->player.move_speed;
	new_y = data->player.pos_y - data->player.dir_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_y][(int)new_x] != '1')
		data->player.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->player.pos_x] != '1')
		data->player.pos_y = new_y;
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = data->player.rot_speed;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(angle)
		- data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle)
		+ data->player.dir_y * cos(angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle)
		+ data->player.plane_y * cos(angle);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	angle = -data->player.rot_speed;
	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(angle)
		- data->player.dir_y * sin(angle);
	data->player.dir_y = old_dir_x * sin(angle)
		+ data->player.dir_y * cos(angle);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(angle)
		- data->player.plane_y * sin(angle);
	data->player.plane_y = old_plane_x * sin(angle)
		+ data->player.plane_y * cos(angle);
}

void	update_player(t_data *data)
{
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.left)
		rotate_left(data);
	if (data->keys.right)
		rotate_right(data);
}
