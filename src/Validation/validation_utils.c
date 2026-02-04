/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:23:44 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/04 15:57:06 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int is_empty_string(char *s)
{
    int i = 0;

    if (!s)
        return (1);
    while (s[i] == ' ' || s[i] == '\t')
        i++;
    return (s[i] == '\0');
}

int has_xpm_extension(char *path)
{
    int len;

    if (!path)
        return (0);
    len = ft_strlen(path);
    if (len < 4)
        return (0);
    if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
        return (0);
    return (1);
}
