#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "cub3d");

	mlx_hook(win, 17, 0, close_window, NULL); // red X button
	mlx_loop(mlx);
	return (0);
}
