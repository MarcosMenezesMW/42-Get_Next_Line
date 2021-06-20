/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:58 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/20 18:21:35 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h> //APAGAR APÓS TESTES
#include <stdlib.h>
#include <sys/select.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char 	*ft_substr(char const *s, unsigned int start, size_t len);

# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL 1

#endif