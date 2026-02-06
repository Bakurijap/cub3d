/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 13:10:01 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// verify if the name of the map is ok
void	check_name(int c, char **v)
{
	int	len;

	if (c != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments", 2);
		exit(1);
	}
	len = ft_strlen(v[1]);
	// i dont handle when a file is just named '.cub'
	if (ft_strncmp(".cub", &v[1][len - 4], 4) != 0)
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
