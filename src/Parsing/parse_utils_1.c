/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:08:16 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 13:09:38 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

int is_number(char *s)
{
    int i = 0;

    if (!s || !s[0])
        return (0);
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
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

void     validate_rgb_format(char **rgb,t_data *data)
{
    int i;
    
    i = 0;
    while (rgb[i])
        i++;
    if (i != 3)
    {
        ft_free_split(rgb);
        error_and_exit(data,"RGB color must have exactly 3 components");
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

void trim_rgb_values(char **rgb)
{
    int i = 0;
    char *tmp;

    while (rgb[i])
    {
        tmp = ft_strtrim(rgb[i], " \n\r\t");
        free(rgb[i]);
        rgb[i] = tmp;
        i++;
    }
}