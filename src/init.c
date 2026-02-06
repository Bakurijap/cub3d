/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:21:38 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 14:43:20 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void init_elements(t_elements *elements)
{
    elements->no = NULL;
    elements->so = NULL;
    elements->we = NULL;
    elements->ea = NULL;
    ft_bzero(elements->set_flags, sizeof(int) * 6);
}

void init_mapinfo(t_mapinfo *mapinfo)
{
    mapinfo->fd = -1;
    mapinfo->line_count = 0;
    mapinfo->path = NULL;
    mapinfo->file = NULL;
    mapinfo->height = 0;
    mapinfo->width = 0;
    mapinfo->index_end_of_map = -1;
}

void    init_data(t_data *data)
{
    ft_bzero(data, sizeof(t_data));
    init_elements(&data->elements);
    init_mapinfo(&data->mapinfo);
    data->elements.f_color = -1;
    data->elements.c_color = -1;
    data->map_start = NULL;
}