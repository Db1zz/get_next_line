/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:05:07 by gonische          #+#    #+#             */
/*   Updated: 2024/07/29 14:03:25 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>			// used for printf
#include <stdbool.h>
#include <unistd.h>

int	ft_read(int	fd, t_data	*data)
{
	data->bytes_read = read(fd, &data->buffer[0], BUFFER_SIZE);
	data->i = 0;
	data->last_fd = fd;
	if (data->bytes_read >= 0)
		data->buffer[data->bytes_read] = '\0';
	return(data->bytes_read);
}

char	*ft_get_line(t_node *line)
{
	char	*result;
	size_t	total_len;
	size_t	i;
	t_node	*tail;

	if (line == NULL)
		return (NULL);
	tail = line;
	total_len = 0;
	while (tail)
	{
		total_len += ft_strlen(tail->data);
		tail = tail->next;
	}
	tail = line;
	result = ft_calloc(total_len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (tail)
	{
		i += ft_strlcpy(&result[i], tail->data, total_len - i);
		tail = tail->next;
	}
	return (result);
}

void	ft_free(t_node *line)
{
	t_node	*next;

	while(line)
	{
		next = line->next;
		free(line->data);
		free(line);
		line = next;
	}
}

char	*get_next_line(int fd)
{
	static t_data	data;
	char			*result;
	t_node			*line;
	t_node			*tail;
	int				i;

	result = NULL;
	line = ft_get_new_node(NULL);
	tail = line;
	i = 0;
	while (true)
	{
		if (data.i >= BUFFER_SIZE || data.buffer[data.i] == '\0')
			data.bytes_read = ft_read(fd, &data);
		if ((data.bytes_read <= 0 && data.buffer[data.i] == '\0')
			|| (i > 0 && tail->data[i - 1] == '\n'))
			break ;
		if (tail->data[i] == '\0' && i > 0)
		{
			tail->next = ft_get_new_node(NULL);
			tail = tail->next;
			i = 0;
		}
		tail->data[i++] = data.buffer[data.i++];
	}
	if (line->data[0])
		result = ft_get_line(line);
	ft_free(line);
	return (result);
}
