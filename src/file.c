/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:58:58 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 15:27:29 by bjaparid         ###   ########.fr       */
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

static int	is_dir(char *filename)
{
	int		fd;
	bool	ret;

	ret = 0;
	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = 1;
	}
	return (ret);
}


void check_filetype(char *filename)
{
    int fd;
    int len;
    
	if (is_dir(filename))
        error_and_exit(NULL, "Error: Provided path is a directory.");
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_and_exit(NULL, strerror(errno));
    len = ft_strlen(filename);
    if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
        error_and_exit(NULL, "Error: Invalid file type. Expected a .cub file.");
}
