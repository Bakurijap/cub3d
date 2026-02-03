/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:30:18 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/03 16:00:10 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void error_and_exit(t_data *data,char *msg)
{
    if (msg)
        fprintf(stderr, "%s", msg);
    else
        fprintf(stderr, "Error\n");
    free_data(data);
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
            return ;	
        current = current->next;
	}
	if (!check_elements_complete(data))
		error_and_exit(data,"Incomplete elements\n");
	while (current && is_line_empty(current->value))
		current = current->next;
	if (!current)
		error_and_exit(data,"Missing map\n");
	data->map_start = current;
	printf("Map starts at line: %s\n", data->map_start->value);
}
