/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:36 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/21 21:04:11 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int	manage_bytes(char *file_read, char **buffer)
{
	char	*tmp;

	tmp = NULL;
	if (*buffer == NULL)
	{
		*buffer = ft_strdup(file_read);
		if (!*buffer)
		{
			free(file_read);
			return (GNL_ERROR);
		}
	}
	else
	{
		tmp = ft_strjoin(*buffer, file_read);
		if (!tmp)
			return (GNL_ERROR);
		free(*buffer);
		*buffer = tmp;
	}
	return (GNL);
}

int	get_new_line(char **buffer, char **line, char *remaining_bytes)
{
	char	*temp;
	size_t	size;

	size = remaining_bytes - *buffer;
	*line = ft_substr(*buffer, 0, size);
	temp = ft_strdup(&(*buffer)[size + 1]);
	free(*buffer);
	*buffer = temp;
	return (GNL);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer[FD_SETSIZE];
	char		file_read[BUFFER_SIZE + 1];
	char		*remaining_bytes;
	int			bytes_read;

	if (!line || fd < 0)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, file_read, BUFFER_SIZE);
		if (bytes_read < 0)
			return (GNL_ERROR);
		file_read[bytes_read] = '\0';
		if (!manage_bytes(file_read, &buffer[fd]) && bytes_read != 0)
			return (GNL_ERROR);
		remaining_bytes = ft_strchr(buffer[fd]);
		if (remaining_bytes != NULL)
			return (get_new_line(&buffer[fd], line, remaining_bytes));
	}
	*line = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (GNL_EOF);
}
