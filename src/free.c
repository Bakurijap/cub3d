/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/01/24 17:52:22 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	free_line_list(t_line **lst)
{
	t_line	*current;
	t_line	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void    free_data(t_data *data)
{
    if (!data)
        return ;
    free_line_list(&data->line);
}

void ft_free_split(char **split)
{
    int i;

    if (!split)
        return ;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}