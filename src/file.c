/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   file.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/01/24 15:58:58 by username         #+#    #+#              */
/*   Updated: 2026/03/23 00:29:25 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

static int	is_dir(char *filename)
{
	int		fd;
	bool	ret;

	ret = 0;
	fd = open(filename, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ret = 1;
	}
	return (ret);
}

void	check_filetype(char *filename)
{
	int	fd;
	int	len;

	if (is_dir(filename))
		error_and_exit(NULL, "Error: Provided path is a directory.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_and_exit(NULL, strerror(errno));
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		error_and_exit(NULL, "Error: Invalid file type. Expected a .cub file.");
}
