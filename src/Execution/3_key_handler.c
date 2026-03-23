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

int	close_game(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys.w = 1;
	else if (keycode == KEY_S)
		data->keys.s = 1;
	else if (keycode == KEY_A)
		data->keys.a = 1;
	else if (keycode == KEY_D)
		data->keys.d = 1;
	else if (keycode == KEY_LEFT)
		data->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		data->keys.right = 1;
	else if (keycode == KEY_ESC)
		close_game(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys.w = 0;
	else if (keycode == KEY_S)
		data->keys.s = 0;
	else if (keycode == KEY_A)
		data->keys.a = 0;
	else if (keycode == KEY_D)
		data->keys.d = 0;
	else if (keycode == KEY_LEFT)
		data->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		data->keys.right = 0;
	return (0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx.win_ptr, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx.win_ptr, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx.win_ptr, 17, 0, close_game, data);
}

int	render_frame(t_data *data)
{
	int		x;
	t_ray	ray;

	update_player(data);
	draw_background(data);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(data, &ray, x);
		init_dda(data, &ray);
		real_dda(data, &ray);
		calculate_wall(&ray);
		draw_wall_texture(data, &ray, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx.mlx_ptr,
		data->mlx.win_ptr, data->screen.img_ptr, 0, 0);
	return (0);
}
