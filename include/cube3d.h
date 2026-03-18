/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:58:43 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 15:39:06 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include "../gnl/get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>

#define E_NO 1
#define E_SO 2
#define E_WE 3
#define E_EA 4
#define E_F  5
#define E_C  6

typedef struct s_line
{
	char			*value;
	struct s_line	*next;
}	t_line;

typedef struct s_elements
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f_color;
	int		c_color;
	int		set_flags[6];
}	t_elements;

typedef struct s_mapinfo
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			index_end_of_map;
}	t_mapinfo;

// Connection a minilibix + window
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

// image
typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;
// texture
typedef struct s_tex
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_tex;
// Player
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	char	start_dir;
}	t_player;
// touche
typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_keys;

typedef struct s_data 
{
	t_line		*line;
	t_elements	elements;
	t_line		*map_start;
	t_mapinfo	mapinfo;
	char		**map;
	int			map_width;
	int			map_height;
	t_mlx		mlx;
	t_img		screen;
	t_tex		no_tex;
	t_tex		so_tex;
	t_tex		we_tex;
	t_tex		ea_tex;
	t_player	player;
	t_keys		keys;
}	t_data;

// check_file
void    check_file(int c, char **v, t_data *data);
void	check_name(int c, char **v);
void	open_test(char *map);
void    check_filetype(char *filename);
// check_map
t_line	*file_to_line_list(char *path);
void	print_line_list(t_line *lst);
int     create_map(t_data *data, t_line *current);
int     is_map_line(char *line);
int find_longest_map_line(t_line *current);
// node
t_line	*create_line(char *value);
int		add_line(t_line **lst, char *value);
void	free_line_list(t_line **lst);


// free
void    free_data(t_data *data);
void	ft_free_split(char **split);
void    error_and_exit(t_data *data,char *msg);
// init
void    init_data(t_data *data);

// parse
//void	step_4(t_data *data, t_line	*current);
int		check_elements_complete(t_data *data);
void    parse_data(t_data *data);
int	    is_line_empty(char *line);
int	    parse_element_line(t_data *data, char *line);
int	    get_element_type(char *line);
char	*skip_id_and_spaces(char *line, int id_len);
int	    parse_texture(t_data *data, int type, char *line);
int	    parse_color(t_data *data, int type, char *line);
void    validate_rgb_format(char **rgb,t_data *data);
int     is_number(char *s);
void    trim_rgb_values(char **rgb);

//validation 
void	validate_textures(t_data *data);
int		is_empty_string(char *s);
int		has_xpm_extension(char *path);
void	validate_each_texture(t_data *data, char *path);

void	check_map_closed(t_data *data);
void	find_player(t_data *data);
char	**copy_map(char **map, int height);
void	flood_fill(t_data *data, char **map, int x, int y);
void	check_map_characters(t_data *data);
void	check_player_count(t_data *data);
#endif