/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:30:57 by marvin            #+#    #+#             */
/*   Updated: 2025/02/04 10:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 70
# endif

struct					s_list
{
	char			*read_now;
	struct s_list	*next;
};

int				check_new_line(struct s_list *tamp);
int				len(char *s);
void			line_len(char **line, struct s_list *tamp);
struct s_list	*get_end_of_list(struct s_list *tamp);
void			pushback(struct s_list **tamp, char *buff, int cursor);
char			*get_next_line(int fd);
void			read_and_add_to_tamp(int fd, struct s_list **tamp, int *cursor);
void			malloc_line(struct s_list *tamp, char **line);
void			clean_and_free(struct s_list **tamp);
void			free_list(struct s_list *tamp);

#endif