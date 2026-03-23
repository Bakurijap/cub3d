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

void	load_texture(t_data *data, t_tex *tex, char *path)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			path, &tex->width, &tex->height);
	if (!tex->img_ptr)
		error_and_exit(data, "Texture loading failed");
	tex->addr = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
}

void	init_textures(t_data *data)
{
	load_texture(data, &data->no_tex, data->elements.no);
	load_texture(data, &data->so_tex, data->elements.so);
	load_texture(data, &data->we_tex, data->elements.we);
	load_texture(data, &data->ea_tex, data->elements.ea);
}

t_tex	*select_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			return (&data->we_tex);
		else
			return (&data->ea_tex);
	}
	else
	{
		if (ray->ray_dir_y < 0)
			return (&data->no_tex);
		else
			return (&data->so_tex);
	}
}
