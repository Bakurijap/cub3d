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

void	init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		error_and_exit(data, "MLX init failed");
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			WIDTH, HEIGHT, "cub3D");
	if (!data->mlx.win_ptr)
		error_and_exit(data, "Window creation failed");
}

void	init_screen(t_data *data)
{
	data->screen.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (!data->screen.img_ptr)
		error_and_exit(data, "Image creation failed");
	data->screen.addr = mlx_get_data_addr(data->screen.img_ptr,
			&data->screen.bpp,
			&data->screen.line_len,
			&data->screen.endian);
	data->screen.width = WIDTH;
	data->screen.height = HEIGHT;
}

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*add;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	add = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)add = color;
}

void	draw_background(t_data *data)
{
	int				x;
	int				y;
	unsigned int	*line;

	y = 0;
	while (y < HEIGHT)
	{
		line = (unsigned int *)(data->screen.addr + y * data->screen.line_len);
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				line[x] = data->elements.c_color;
			else
				line[x] = data->elements.f_color;
			x++;
		}
		y++;
	}
}
