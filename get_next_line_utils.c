/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:23:07 by gonische          #+#    #+#             */
/*   Updated: 2024/07/29 13:59:50 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	res_size;
	size_t	i;

	res_size = count * size;
	result = (char *)malloc(res_size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < res_size)
		result[i++] = 0;
	return ((void *)result);
}

t_node *ft_get_new_node(char *data)
{
	t_node	*result;

	result = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!result)
		return (NULL);
	if (data)
		result->data = data;
	else
	{
		result->data = (char *)ft_calloc(LINE_DATA_SIZE + 1, sizeof(char));
		if (!result->data)
		{
			free(result);
			return (NULL);
		}
	}
	result->next = NULL;
	return (result);
}

size_t	ft_strlen(const char *str)
{
	size_t	result;

	if (!str)
		return (0);
	result = 0;
	while (str[result])
		result++;		
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = ft_strlen(src);
	if (dstsize == 0)
		return (result);
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (result);
}
