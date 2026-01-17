/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2025/12/14 16:49:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

// open the file and add lines to a list
t_line	*file_to_line_list(char *path)
{
	int		fd;
	char	*line;
	t_line	*lst;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line(&lst, line))
		{
			close(fd);
			free_line_list(&lst);
			return (NULL);
		}
	}
	close(fd);
	return (lst);
}



void	print_line_list(t_line *lst)
{
	while (lst)
	{
		if (lst->value)
			write(1, lst->value, ft_strlen(lst->value));
		lst = lst->next;
	}
}
