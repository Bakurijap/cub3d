/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:15:03 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 17:22:19 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	check_map_closed(t_data *data)
{
	char	**map_copy;
	int		px;
	int		py;

	find_player(data);
	map_copy = copy_map(data->map, data->map_height);
	if (!map_copy)
		error_and_exit(data, "Malloc failed");
	px = (int)data->player.pos_x;
	py = (int)data->player.pos_y;
	// printf("%d\n", (int)data->player.pos_x);
	// printf("%d\n", (int)data->player.pos_y);
	flood_fill(data, map_copy, px, py);
	ft_free_split(map_copy);
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N'
				|| data->map[i][j] == 'S'
				|| data->map[i][j] == 'E'
				|| data->map[i][j] == 'W')
			{
				data->player.pos_x = j + 0.5;
				data->player.pos_y = i + 0.5;
				data->player.start_dir = data->map[i][j];
				// printf("%f\n", data->player.pos_x);
				// printf("%f\n", data->player.pos_y);
				// printf("%c\n", data->player.start_dir);
				return ;
			}
			j++;
		}
		i++;
	}
	error_and_exit(data, "Player not found");
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int	i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(t_data *data, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map_width || y >= data->map_height)
	{
		ft_free_split(map);
		error_and_exit(data, "Map not closed 1");
	}
	if (!map[y] || x >= (int)ft_strlen(map[y]))
	{
		ft_free_split(map);
		error_and_exit(data, "Map not closed 2");
	}
	if (map[y][x] == ' ')
	{
		ft_free_split(map);
		error_and_exit(data, "Map not closed 3");
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;

	map[y][x] = 'V';

	flood_fill(data, map, x + 1, y);
	flood_fill(data, map, x - 1, y);
	flood_fill(data, map, x, y + 1);
	flood_fill(data, map, x, y - 1);
}
