/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:57 by yabou-da          #+#    #+#             */
/*   Updated: 2025/12/14 17:15:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(int c, char **v)
{
	t_line	*lst;
	
	check_name(c, v);
	open_test(v[1]);
	lst = file_to_line_list(v[1]);
	print_line_list(lst);
	free_line_list(&lst);
	return (0);
}

// void	*mlx;
	// void	*win;

	// Very Good but we will use this after the parsing (it can contain leaks if my memory is good)

	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 800, 600, "cub3d");

	// mlx_hook(win, 17, 0, close_window, NULL); // red X button
	// mlx_loop(mlx);