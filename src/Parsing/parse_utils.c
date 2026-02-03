/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:32:12 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/03 16:55:23 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// Skips the identifier and any following spaces in the line
int	parse_texture(t_data *data, int type, char *line)
{
	char	*path;

	path = skip_id_and_spaces(line, 2);
    if (!*path)
		return (0);
	path = ft_strtrim(path, " \n");
	if (!path)
		return (0);
	if (type == E_NO)
		data->elements.no = path;
	else if (type == E_SO)
		data->elements.so = path;
	else if (type == E_WE)
		data->elements.we = path;
	else if (type == E_EA)
		data->elements.ea = path;
	return (1);
}

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
        error_and_exit(data,"Color values must be between 0 and 255\n");
    }
	if (type == E_F)
		data->elements.f_color = (r << 16) | (g << 8) | b;
	else
		data->elements.c_color = (r << 16) | (g << 8) | b;
	ft_free_split(rgb);
	return (1);
}

// Returns the element type based on the line prefix
int	get_element_type(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_strncmp(line + i, "NO ", 3))
		return (E_NO);
	if (!ft_strncmp(line + i, "SO ", 3))
		return (E_SO);
	if (!ft_strncmp(line + i, "WE ", 3))
		return (E_WE);
	if (!ft_strncmp(line + i, "EA ", 3))
		return (E_EA);
	if (!ft_strncmp(line + i, "F ", 2))
		return (E_F);
	if (!ft_strncmp(line + i, "C ", 2))
		return (E_C);
	return (0);
}

int	parse_element_line(t_data *data, char *line) // returns 1 on success, 0 on failure
{
	int	type;

	type = get_element_type(line);
	if (type == 0)
		return (1);
	if (data->elements.set_flags[type]) // already set ?
        error_and_exit(data,"Duplicate element found\n");        
	data->elements.set_flags[type] = 1; // mark as set
	if (type >= E_NO && type <= E_EA) // texture types
		return (parse_texture(data, type, line));
	if (type == E_F || type == E_C) // color types
		return (parse_color(data, type, line));
	return (1);
}

int	is_line_empty(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\r')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}
