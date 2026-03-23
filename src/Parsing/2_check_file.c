/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   2_check_file.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2025/11/27 18:53:16 by username         #+#    #+#              */
/*   Updated: 2026/03/23 00:17:48 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// verify if the name of the map is ok
void	check_name(int c, char **v)
{
	int	len;

	if (c != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(1);
	}
	len = ft_strlen(v[1]);
	if (len < 4 || ft_strncmp(".cub", &v[1][len - 4], 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid file extension (expected .cub)\n", 2);
		exit(1);
	}
}

// open the file to test if it's ok
void	open_test(char *map)
{
	int		fd;
	char	buf[1];
	int		ret;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCannot open file\n", 2);
		exit(1);
	}
	ret = read(fd, buf, 1);
	if (ret == -1)
	{
		ft_putstr_fd("Error\nRead failed\n", 2);
		close(fd);
		exit(1);
	}
	if (ret == 0)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		close(fd);
		exit(1);
	}
	close(fd);
}
