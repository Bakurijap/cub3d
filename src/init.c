/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:21:38 by bjaparid          #+#    #+#             */
/*   Updated: 2026/01/24 17:57:09 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void    init_data(t_data *data)
{
    ft_bzero(data, sizeof(t_data));
    data->elements.f_color = -1;
    data->elements.c_color = -1;
    data->map_start = NULL;
}