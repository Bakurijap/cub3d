/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 13:10:01 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	check_player_count(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
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
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		error_and_exit(data, "No player in map");
	if (count > 1)
		error_and_exit(data, "too many players in map");
}

void	check_map_characters(t_data *data)
{
	int	i;
	int	j;
	char	c;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			c = data->map[i][j];
			if (c != '0' && c != '1' && c != 'N'
				&& c != 'S' && c != 'E' && c != 'W'
				&& c != ' ')
				error_and_exit(data, "Invalid character in map");
			j++;
		}
		i++;
	}
}
