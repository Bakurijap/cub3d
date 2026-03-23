/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing_utils.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/01/24 17:08:16 by username         #+#    #+#              */
/*   Updated: 2026/03/23 00:22:16 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube3d.h"

void	error_and_exit(t_data *data, char *msg)
{
	if (msg)
		fprintf(stderr, "Error\n%s\n", msg);
	else
		fprintf(stderr, "Error\n");
	free_data(data);
	exit(EXIT_FAILURE);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_empty_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (s[i] == '\0');
}

int	has_xpm_extension(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len < 4)
		return (0);
	if (ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (0);
	return (1);
}
