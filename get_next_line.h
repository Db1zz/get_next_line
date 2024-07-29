/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:45:20 by gonische          #+#    #+#             */
/*   Updated: 2024/07/29 12:44:47 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif // BUFFER_SIZE

#ifndef LINE_DATA_SIZE
#define LINE_DATA_SIZE 1024
#endif // LINE_DATA_SIZE

#include <stdlib.h>

typedef struct t_data
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;
	int		bytes_read;
	int		last_fd;
}	t_data;

typedef	struct	t_node
{
	char			*data;
	struct t_node	*next;
}	t_node;

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
t_node *ft_get_new_node(char *data);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
