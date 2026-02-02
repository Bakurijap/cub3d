/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:58:58 by bjaparid          #+#    #+#             */
/*   Updated: 2026/01/24 16:02:51 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

// check the file and store its content in a linked list
void    check_file(int c, char **v, t_data *data)
{
    check_name(c, v);
    open_test(v[1]);
    data->line = file_to_line_list(v[1]);
}