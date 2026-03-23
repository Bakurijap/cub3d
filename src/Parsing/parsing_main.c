/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing_main.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/01/24 16:30:18 by username         #+#    #+#              */
/*   Updated: 2026/03/23 00:22:01 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

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
			continue ;
		}
		if (!parse_element_line(data, current->value))
			return ;
		current = current->next;
	}
	if (!check_elements_complete(data))
		error_and_exit(data, "Incomplete elements");
	while (current && is_line_empty(current->value))
		current = current->next;
	if (!current)
		error_and_exit(data, "Missing map");
	data->map_start = current;
	if (create_map(data, current) == 0)
		error_and_exit(data, "Failed to create map");
}
