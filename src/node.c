/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:45:57 by yabou-da          #+#    #+#             */
/*   Updated: 2025/12/14 16:30:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_line	*create_line(char *value)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->value = value;
	line->next = NULL;
	return (line);
}

int	add_line(t_line **lst, char *value)
{
	t_line	*newnode;
	t_line	*current;

	if (!lst)
	{
		free(value);
		return (0);
	}
	newnode = create_line(value);
	if (!newnode)
	{
		free(value);
		return (0);
	}
	if (*lst == NULL)
	{
		*lst = newnode;
		return (1);
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = newnode;
	return (1);
}
