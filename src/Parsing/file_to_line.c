/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 15:12:48 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"


static char *trim_line(char *line)
{
    int len;
    
    len = ft_strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
    {
        line[len - 1] = '\0';
        len--;
    }
    return line;
}
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
        line = trim_line(line);
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
