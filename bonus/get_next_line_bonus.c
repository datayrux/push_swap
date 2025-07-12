/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-coss <ale-coss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:17:39 by ale-coss          #+#    #+#             */
/*   Updated: 2025/07/09 16:18:55 by ale-coss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ((char)c))
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_jonction(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*alloc;

	if (!s1)
		alloc = malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		alloc = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!alloc)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	if (alloc)
	{
		while (s1 && s1[i])
		{
			alloc[i] = s1[i];
			i++;
		}
		while (s2[j])
			alloc[i++] = s2[j++];
		alloc[i] = '\0';
	}
	free(s1);
	return (alloc);
}

char	*get_a_line(char *remaining)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (remaining[i] && remaining[i] != '\n')
		i++;
	i += (remaining[i] == '\n');
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = remaining[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*update_remaining(char *remaining, char *line)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strlen(line);
	j = 0;
	if (!remaining[i])
	{
		free(remaining);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strlen(remaining) - i + 1));
	if (!new)
		return (free(remaining), remaining = NULL, NULL);
	while (remaining[i])
		new[j++] = remaining[i++];
	new[j] = '\0';
	free(remaining);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*remaining;
	char		*line;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !buffer)
		return (free(remaining), free(buffer), remaining = NULL, NULL);
	bytes_read = 1;
	while (!ft_strchr(remaining, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(remaining), free(buffer), remaining = NULL, NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read)
			remaining = ft_jonction(remaining, buffer);
	}
	if (!remaining)
		return (free(remaining), free(buffer), remaining = NULL, NULL);
	line = get_a_line(remaining);
	if (!line)
		return (free(remaining), free(buffer), remaining = NULL, NULL);
	remaining = update_remaining(remaining, line);
	return (free(buffer), line);
}
