/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:08:16 by bjaparid          #+#    #+#             */
/*   Updated: 2026/01/24 17:45:11 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

char	*skip_id_and_spaces(char *line, int id_len)
{
	int	i;

	i = id_len;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
    return (line + i);
}