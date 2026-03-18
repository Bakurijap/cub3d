/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjaparid <bjaparid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:15:03 by bjaparid          #+#    #+#             */
/*   Updated: 2026/02/06 17:22:19 by bjaparid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

static int get_map_height(t_line *current)
{
    int height;

    height = 0;
    while (current && is_map_line(current->value))
    {
        height++;
        current = current->next;
    }
    return (height);
}

static int fill_map_array(t_data *data, t_line *current)
{
    int i;
    int j;
    
    i = 0;
    data->map_width = find_longest_map_line(current);
    printf("map_width = %d\n", data->map_width);
    //data->map_width = data->map_width + 1;
    while (current && is_map_line(current->value))
    {   
        j = 0;
        data->map[i] = malloc(sizeof(char) * (data->map_width + 1));
        if (!data->map[i])
            error_and_exit(data,"Failed to allocate memory for map line");
        while(current->value[j] && current->value[j] != '\n')
        {
            data->map[i][j] = current->value[j];
            j++;
        }
        while (j < data->map_width)
			data->map[i][j++] = '\0';
        data->map[i][j] = '\0'; // null-terminate the string
        current = current->next;
        i++;
    }
    data->map[i] = NULL; // null-terminate the array
    return (1);
}

// this function will create the 2D map array from the linked list of lines starting at current,
 // it will also set map_width and map_height in data
static int create_map_from_list(t_data *data, t_line *current)
{
    data->mapinfo.height = get_map_height(current);
    data->map_height = get_map_height(current);
    data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
    if (!data->map)
        error_and_exit(data,"Failed to allocate memory for map");
    if(fill_map_array(data,current) == 0) // this function will fill the map array and set map_width
        error_and_exit(data,"Failed to fill map from list");
    return (1);
}

static void convert_space_into_wall(t_data *data)
{
    int i;
    int j;

    i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
		|| data->map[i][j] == '\r'
		|| data->map[i][j] == '\v' || data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' '
				&& j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

int create_map(t_data *data, t_line *current) // returns 1 on success, 0 on failure
{
    if(create_map_from_list(data,current) == 0) // this function also sets map_width and map_height
        error_and_exit(data,"Failed to create map from list");
    convert_space_into_wall(data); // this is needed to make the map valid for the validation step, 
    //it will convert all spaces into '1' (wall) and all other characters will be left unchanged
    return (1);
}