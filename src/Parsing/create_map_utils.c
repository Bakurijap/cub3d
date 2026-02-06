/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:28:13 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 15:34:12 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int is_map_line(char *line)
{
    int i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t' || line[i] == '\r'
		|| line[i] == '\v' || line[i] == '\f')
    {
        i++;
    }
	if (line[i] != '1')
			return (0);
    return (1);
}

int find_longest_map_line(t_line *current)
{
    int max_length;

    max_length = 0;
    while (current && is_map_line(current->value))
    {
        if ((int)ft_strlen(current->value) > max_length)
            max_length = ft_strlen(current->value);
        current = current->next;
    }
    return (max_length);
}