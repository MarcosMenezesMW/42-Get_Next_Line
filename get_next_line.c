/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:36 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/21 20:05:35 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_strchr(const char *s)
// {
// 	while (*s)
// 	{
// 		if (*s == '\n')
// 			return ((char *)s);
// 		s++;
// 	}
// 	return (NULL);
// }

// int	manage_bytes(char *file_read, char **buffer)
// {
// 	char	*tmp;

// 	tmp = NULL;
// 	if (*buffer == NULL)
// 	{
// 		*buffer = ft_strdup(file_read);
// 		if (!*buffer)
// 		{
// 			free(file_read);
// 			return (GNL_ERROR);
// 		}
// 	}
// 	else
// 	{
// 		tmp = ft_strjoin(*buffer, file_read);
// 		if (!tmp)
// 			return (GNL_ERROR);
// 		free(*buffer);
// 		*buffer = tmp;
// 	}
// 	return (GNL);
// }

// int	get_new_line(char **buffer, char **line, char *remaining_bytes)
// {
// 	char	*temp;
// 	size_t	size;

// 	size = remaining_bytes - *buffer;
// 	*line = ft_substr(*buffer, 0, size);
// 	temp = ft_strdup(&(*buffer)[size + 1]);
// 	free(*buffer);
// 	*buffer = temp;
// 	return (GNL);
// }

// int	get_next_line(int fd, char **line)
// {
// 	static char	*buffer;
// 	char		file_read[BUFFER_SIZE + 1];
// 	char		*remaining_bytes;
// 	int			bytes_read;

// 	if (!line || fd < 0)
// 		return (-1);
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, file_read, BUFFER_SIZE);
// 		if (bytes_read < 0)
// 			return (GNL_ERROR);
// 		file_read[bytes_read] = '\0';
// 		if (!manage_bytes(file_read, &buffer) && bytes_read != 0)
// 			return (GNL_ERROR);
// 		remaining_bytes = ft_strchr(buffer);
// 		if (remaining_bytes != NULL)
// 			return (get_new_line(&buffer, line, remaining_bytes));
// 	}
// 	*line = ft_strdup(buffer);
// 	free(buffer);
// 	buffer = NULL;
// 	return (GNL_EOF);
// }

int			get_buffer(char *from_read, char **buffer)
{
	char	*temp;
	
	temp = NULL;
	if (!*buffer)
	{
		*buffer = strdup(from_read);
		if (!*buffer);
			return (GNL_ERROR);
		free(from_read);
	}
	else
	{
		temp = ft_str_join(*buffer, from_read);
		free(*buffer);
		*buffer = temp;
		if(!*buffer)
			return(GNL_ERROR);
	}
	return (GNL);
}

static int	get_newline(char **buffer, char **new_line, char ** line)
{
	size_t	len;
	char	*temp;

	len = *new_line - *buffer;
	*line = ft_substr(*buffer, 0, len);
	temp = strdup(&(*buffer)[len + 1]);
	free (*buffer);
	*buffer = temp;
	return (GNL);	
}

int			get_next_line(int fd, char **line)
{
	static char 	*buffer;
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
		if (!get_buffer(from_read, &buffer) && from_read != 0)
			return(GNL_ERROR);
		new_line = ft_strchr(buffer);
		if (new_line != NULL)
			return (get_new_line(&buffer, &line, &new_line));
	}
	*line = strdup(buffer);
	free(buffer);
	buffer = NULL;
	return (GNL_EOF);
}