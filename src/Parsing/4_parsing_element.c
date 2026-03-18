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

// returns 1 on success, 0 on failure
int	parse_element_line(t_data *data, char *line)
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


int	check_elements_complete(t_data *data)
{
	if (!data->elements.no || !data->elements.so || !data->elements.we || \
		!data->elements.ea || data->elements.f_color == -1 || \
		data->elements.c_color == -1)
		return (0);
	return (1);
}
