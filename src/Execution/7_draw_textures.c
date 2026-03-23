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

void	draw_wall_texture(t_data *data, t_ray *ray, int x)
{
	t_tex	*tex;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		y;

	tex = select_texture(data, ray);
	tex_x = get_tex_x(data, ray, tex);
	step = (double)tex->height / ray->line_height;
	tex_pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		pixel_put(&data->screen, x, y, get_texture_pixel(tex, tex_x, tex_y));
		tex_pos += step;
		y++;
	}
}

double	get_wall_x(t_data *data, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_tex_x(t_data *data, t_ray *ray, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	wall_x = get_wall_x(data, ray);
	tex_x = (int)(wall_x * (double)tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int	get_texture_pixel(t_tex *tex, int x, int y)
{
	char	*dst;

	dst = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}
