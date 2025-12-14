/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:58:43 by yabou-da          #+#    #+#             */
/*   Updated: 2025/12/14 16:55:54 by marvin           ###   ########.fr       */
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

typedef struct s_line
{
	char			*value;
	struct s_line	*next;
}	t_line;


// check_file
void	check_name(int c, char **v);
void	open_test(char *map);

// check_map
t_line	*file_to_line_list(char *path);
void	print_line_list(t_line *lst);

// node
t_line	*create_line(char *value);
int		add_line(t_line **lst, char *value);
void	free_line_list(t_line **lst);

#endif