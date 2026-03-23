/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   5_parsing_color.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/11/27 18:53:16 by username         #+#    #+#              */
/*   Updated: 2026/03/23 00:19:32 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// Parses floor and ceiling colors
int	parse_color(t_data *data, int type, char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	char	*str;

	str = skip_id_and_spaces(line, 1);
	rgb = ft_split(str, ',');
	trim_rgb_values(rgb);
	validate_rgb_format(rgb, data);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		return (0);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_free_split(rgb);
		error_and_exit(data, "Color values must be between 0 and 255");
	}
	if (type == E_F)
		data->elements.f_color = (r << 16) | (g << 8) | b;
	else
		data->elements.c_color = (r << 16) | (g << 8) | b;
	ft_free_split(rgb);
	return (1);
}

char	*skip_id_and_spaces(char *line, int id_len)
{
	int	i;

	i = id_len;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line + i);
}

void	validate_rgb_format(char **rgb, t_data *data)
{
	int	i;

	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
	{
		ft_free_split(rgb);
		error_and_exit(data, "RGB color must have exactly 3 components");
	}
	if (rgb[0][0] == '\0' || rgb[1][0] == '\0' || rgb[2][0] == '\0')
	{
		ft_free_split(rgb);
		error_and_exit(data, "Color values cannot be empty");
	}
	if (!is_number(rgb[0]) || !is_number(rgb[1]) || !is_number(rgb[2]))
	{
		ft_free_split(rgb);
		error_and_exit(data, "Color must contain only numbers");
	}
}

void	trim_rgb_values(char **rgb)
{
	int		i;
	char	*tmp;

	i = 0;
	while (rgb[i])
	{
		tmp = ft_strtrim(rgb[i], " \n\r\t");
		free(rgb[i]);
		rgb[i] = tmp;
		i++;
	}
}
