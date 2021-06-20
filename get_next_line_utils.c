/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mameneze <mwmms@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:24:44 by mameneze          #+#    #+#             */
/*   Updated: 2021/06/20 19:23:47 by mameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*newstring;
	int		i;

	i = 0;
	newstring = malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (!newstring)
		return (NULL);
	while (s[i] != '\0')
	{
		newstring[i] = s[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		newstring[i] = s2[j];
		i++;
		j++;
	}
	newstring[i] = '\0';
	return (newstring);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	last_char;

	i = 0;
	last_char = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
	{
		if (i + 1 < size)
		{
			last_char++;
			dst[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dst[last_char] = '\0';
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	max_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start < s_len)
		max_len = s_len - start;
	else
		max_len = 0;
	if (max_len > len)
		max_len = len;
	substr = malloc(sizeof(char) * (max_len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, max_len + 1);
	return (substr);
}
