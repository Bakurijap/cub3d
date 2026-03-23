/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:53:16 by yabou-da          #+#    #+#             */
/*   Updated: 2026/02/06 17:32:16 by bjaparid         ###   ########.fr       */
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

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_line_list(&data->line);
	free_elements(data);
	ft_free_split(data->map);
	free_mlx(data);
}

void	ft_free_split(char **split)
{
	int	i;

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

void	free_mlx(t_data *data)
{
	if (data->screen.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->screen.img_ptr);
	if (data->no_tex.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->no_tex.img_ptr);
	if (data->so_tex.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->so_tex.img_ptr);
	if (data->we_tex.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->we_tex.img_ptr);
	if (data->ea_tex.img_ptr)
		mlx_destroy_image(data->mlx.mlx_ptr, data->ea_tex.img_ptr);
	if (data->mlx.win_ptr)
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	if (data->mlx.mlx_ptr)
	{
		mlx_destroy_display(data->mlx.mlx_ptr);
		free(data->mlx.mlx_ptr);
	}
}
