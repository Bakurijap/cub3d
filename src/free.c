/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/03 15:48:54 by bjaparid         ###   ########.fr       */
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

void	free_elements(t_data *data)
{
    if (!data)
    {
        write(2, "free_elements: data is NULL\n", 29);
        return ;
    }
    if (data->elements.no)
		free(data->elements.no);
	if (data->elements.so)
		free(data->elements.so);
	if (data->elements.we)
		free(data->elements.we);
	if (data->elements.ea)
		free(data->elements.ea);
}


void    free_data(t_data *data)
{
    if (!data)
        return ;
    free_line_list(&data->line);
    free_elements(data);
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