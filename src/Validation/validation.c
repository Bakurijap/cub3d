/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:22:58 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 17:26:52 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"


void check_empty_string(t_data data)
{
    if(data.elements.no && is_empty_string(data.elements.no))
    {
        error_and_exit(&data, "Error: North texture path is empty in the .cub file.");
    }
    if(data.elements.so && is_empty_string(data.elements.so))
        error_and_exit(&data, "Error: South texture path is empty in the .cub file.");
    if(data.elements.we && is_empty_string(data.elements.we))
        error_and_exit(&data,"Error: West texture path is empty in the .cub file.");
    if(data.elements.ea && is_empty_string(data.elements.ea))
        error_and_exit(&data,"Error: East texture path is empty in the .cub file");
}

void check_xpm_extension(t_data *data)
{
    if(data->elements.no && !has_xpm_extension(data->elements.no))
        error_and_exit(data,"Error: North texture does not have .xpm extension");
    if(data->elements.so && !has_xpm_extension(data->elements.so))
        error_and_exit(data,"Error: South texture does not have .xpm extension");
    if(data->elements.we && !has_xpm_extension(data->elements.we))
        error_and_exit(data,"Error: West texture does not have .xpm extension");
    if(data->elements.ea && !has_xpm_extension(data->elements.ea))
        error_and_exit(data,"Error: East texture does not have .xpm extension");
}

void validate_each_texture(t_data *data, char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    is_empty_string(path);
    check_xpm_extension(data);
    if (fd < 0)
        error_and_exit(data,"Error: Failure to open texture file");
    close(fd);
}   

void validate_textures(t_data *data)
{
    validate_each_texture(data,data->elements.no);
    validate_each_texture(data,data->elements.so);
    validate_each_texture(data,data->elements.we);
    validate_each_texture(data,data->elements.ea);
}
