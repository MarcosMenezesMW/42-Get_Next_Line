/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:36 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/22 21:57:12 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_buffer(char *from_read, char **buffer)
{
	char	*temp;

	temp = NULL;
	if (!*buffer)
	{
		*buffer = ft_strdup(from_read);
		if (!*buffer)
		{
			free(from_read);
			return (GNL_ERROR);
		}
	}
	else
	{
		temp = ft_strjoin(*buffer, from_read);
		free(*buffer);
		*buffer = temp;
		if (!*buffer)
			return (GNL_ERROR);
	}
	return (GNL);
}

static int	get_newline(char **buffer, char **new_line, char **line)
{
	size_t	len;
	char	*temp;

	len = *new_line - *buffer;
	*line = malloc(len + 1);
	ft_strlcpy(*line, *buffer, len + 1);
	temp = ft_strdup(&(*buffer)[len + 1]);
	free (*buffer);
	*buffer = temp;
	return (GNL);
}

int	get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			from_read[BUFFER_SIZE + 1];
	char			*new_line;
	int				bytes_read;

	if (!line || fd < 0)
		return (GNL_ERROR);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, from_read, BUFFER_SIZE);
		if (bytes_read < 0)
			return (GNL_ERROR);
		from_read[bytes_read] = '\0';
		if (!get_buffer(from_read, &buffer) && bytes_read != 0)
			return (GNL_ERROR);
		new_line = ft_strchr(buffer);
		if (new_line != NULL)
			return (get_newline(&buffer, &new_line, line));
	}
	*line = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (GNL_EOF);
}
