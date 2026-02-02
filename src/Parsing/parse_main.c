/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:30:18 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/03 00:29:40 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void error_and_exit(void)
{
    fprintf(stderr, "Error\n");
    exit(EXIT_FAILURE);
}

static int   check_elements_complete(t_data *data)
{
    if (!data->elements.no || !data->elements.so || !data->elements.we || \
        !data->elements.ea || data->elements.f_color == -1 || \
        data->elements.c_color == -1)
        return (0);
    return (1);
}

void	parse_data(t_data *data)
{
	t_line	*current;

	current = data->line;

	while (current && is_line_empty(current->value))
		current = current->next;
	while (current && !check_elements_complete(data))
	{
		if (is_line_empty(current->value))
		{
			current = current->next;
			continue;
		}
		if (!parse_element_line(data, current->value))
			error_and_exit();
		current = current->next;
	}
	if (!check_elements_complete(data))
	{
		write(2, "Incomplete elements\n", 21);
		error_and_exit();
	}
	while (current && is_line_empty(current->value))
		current = current->next;
	if (!current)
	{
		write(2, "Missing map\n", 13);
		error_and_exit();
	}
	data->map_start = current;
	printf("Map starts at line: %s\n", data->map_start->value);
}
