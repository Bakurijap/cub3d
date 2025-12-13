/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:31:39 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 10:31:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(struct s_list *tamp)
{
	int				i;
	struct s_list	*current;

	i = 0;
	if (tamp == NULL)
		return (0);
	current = get_end_of_list(tamp);
	while (current->read_now[i])
	{
		if (current->read_now[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

struct s_list	*get_end_of_list(struct s_list *tamp)
{
	struct s_list	*current;

	current = tamp;
	while (current->next)
		current = current->next;
	return (current);
}

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	line_len(char **line, struct s_list *tamp)
{
	int	i;
	int	count;

	count = 0;
	while (tamp)
	{
		i = 0;
		while (tamp->read_now[i])
		{
			if (tamp->read_now[i] == '\n')
			{
				count++;
				break ;
			}
			count++;
			i++;
		}
		tamp = tamp->next;
	}
	*line = malloc((count + 1) * sizeof(char));
}

void	pushback(struct s_list **tamp, char *buff, int cursor)
{
	struct s_list	*newnode;
	struct s_list	*current;
	int				i;

	i = 0;
	newnode = malloc(sizeof(struct s_list));
	if (newnode == NULL || cursor == -1)
		return ;
	newnode->next = NULL;
	newnode->read_now = malloc((cursor + 1) * sizeof(char));
	if (newnode->read_now == NULL)
		return ;
	while (i < cursor)
	{
		newnode->read_now[i] = buff[i];
		i++;
	}
	newnode->read_now[i] = '\0';
	if (*tamp == NULL)
	{
		*tamp = newnode;
		return ;
	}
	current = get_end_of_list(*tamp);
	current->next = newnode;
}
/*
void	PrintList(struct s_list *list)
{
	struct s_list	*current;

	current = list;
	while (current != NULL)
	{
		printf("%s\n", current->read_now);
		current = current->next;
	}
}

int	main(void)
{
	size_t len = 0;
	struct s_list *liste = NULL;
	char *a = "1234";
	char *b = "123";
	char *c = "12";
	char *d = "14\n958";

	len = pushback(&liste, a);
	// PrintList(liste);
	// printf("la longueur de la liste est %d\n",len);

	len = pushback(&liste, b);
	// PrintList(liste);
	// printf("la longueur de la liste est %d\n",len);

	len = pushback(&liste, c);
	// PrintList(liste);
	// printf("la longueur de la liste est %d\n",len);

	len = pushback(&liste, d);
	PrintList(liste);
	printf("la longueur de la liste est %d\n",len);

	clean(&liste, check_new_line(d));
	PrintList(liste);
	//printf("%s\n", malloc_line(&liste, len));
	return (0);
}*/