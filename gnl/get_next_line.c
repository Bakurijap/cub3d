/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:26:44 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 10:26:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char					*line;
	static struct s_list	*tamp = NULL;
	int						cursor;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	cursor = 5;
	read_and_add_to_tamp(fd, &tamp, &cursor);
	if (!tamp || cursor < 0)
	{
		free_list(tamp);
		tamp = NULL;
		return (NULL);
	}
	malloc_line(tamp, &line);
	clean_and_free(&tamp);
	if (line[0] == '\0')
	{
		free_list(tamp);
		tamp = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_add_to_tamp(int fd, struct s_list **tamp, int *cursor)
{
	char	*buff;

	while (check_new_line(*tamp) == 0 && *cursor != 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		*cursor = read(fd, buff, BUFFER_SIZE);
		if ((!(*tamp) && *cursor == 0) || *cursor == -1)
		{
			free(buff);
			return ;
		}
		buff[*cursor] = '\0';
		pushback(tamp, buff, *cursor);
		free(buff);
	}
}

void	malloc_line(struct s_list *tamp, char **line)
{
	size_t		i;
	size_t		j;

	if (tamp == NULL)
		return ;
	line_len(line, tamp);
	if (*line == NULL)
		return ;
	i = 0;
	while (tamp != NULL)
	{
		j = 0;
		while (tamp->read_now[j])
		{
			if (tamp->read_now[j] == '\n')
			{
				(*line)[i++] = '\n';
				break ;
			}
			(*line)[i++] = tamp->read_now[j++];
		}
		tamp = tamp->next;
	}
	(*line)[i] = '\0';
}

void	clean_and_free(struct s_list **tamp)
{
	struct s_list	*current;
	struct s_list	*ntamp;
	int				i;
	int				j;

	ntamp = malloc(sizeof(struct s_list));
	if (!tamp || !ntamp)
		return ;
	ntamp->next = NULL;
	current = get_end_of_list(*tamp);
	i = 0;
	while (current->read_now[i] && current->read_now[i] != '\n')
		i++;
	if (current->read_now[i] == '\n')
		i++;
	ntamp->read_now = malloc((len(current->read_now) - i + 1) * sizeof(char));
	if (ntamp->read_now == NULL)
		return ;
	j = 0;
	while (current->read_now[i])
		ntamp->read_now[j++] = current->read_now[i++];
	ntamp->read_now[j] = '\0';
	free_list(*tamp);
	*tamp = ntamp;
}

void	free_list(struct s_list *tamp)
{
	struct s_list	*current;
	struct s_list	*next;

	current = tamp;
	while (current != NULL)
	{
		free(current->read_now);
		next = current->next;
		free(current);
		current = next;
	}
}
/*
int	main(void)
{
	int		fd;
	char	*ligne;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 1;
	while(i == 1)
	{
		ligne = get_next_line(fd);
		printf("%s",ligne);
		if (ligne == NULL)
			break;
		free(ligne);
	}
	return (0);
}*/