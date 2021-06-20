/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:36 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/20 15:08:02 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line (char **line, char **buffer)
{
	int i;
	char *temp;
	
	i = 0;
	while (*buffer[i] != '\n')
	{
		*line[i] = *buffer[i];
		i++;
	}
	*line[i] = '\0';
	temp = ft_strdup(&(*buffer)[i + 1]);
	free(*buffer);
	*buffer = temp;
	return (GNL);
}

static int	treat_bytes_read(char *from_read, char **buffer)
{
	char	*temp;
	
	temp = NULL;
	if (*buffer == NULL)
	{
		*buffer = ft_strdup(from_read);
		if (!*buffer)
		{
			free (from_read);
			return (GNL_ERROR);
		}
	}
	else
	{
		temp = ft_strjoin(*buffer, from_read);
		if(!temp)
			return (GNL_ERROR);
		free (*buffer);
		*buffer = temp;
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			from_read[BUFFER_SIZE + 1];
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
		if (!treat_bytes_read(from_read, &buffer) && bytes_read != 0)
			return (GNL_ERROR);
		if (ft_strchr(buffer, '\n') != NULL)
			return (get_line(line, &buffer));			
	}
	*line = ft_strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (GNL_EOF);
}
