/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:58:43 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/03 16:55:53 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "libft.h"
# include "mlx.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_data 
{
    t_line       *line;
    t_elements  elements;
    t_line		*map_start;
}   t_data;

// check_file
void    check_file(int c, char **v, t_data *data);
void	check_name(int c, char **v);
void	open_test(char *map);

// check_map
t_line	*file_to_line_list(char *path);
void	print_line_list(t_line *lst);

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
#endif