/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:02:04 by abarrio           #+#    #+#             */
/*   Updated: 2026/02/14 14:39:00 by abarrio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
			stash = ft_strjoin(stash, buffer);
	}
	return (free(buffer), stash);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_clean_stash(char *stash)
{
	char	*new_stash;
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	if (!stash[i])
		return (free(stash), NULL);
	new_stash = ft_strjoin(NULL, stash + i);
	if (!new_stash)
		return (free(stash), NULL);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (stash = NULL, NULL);
	line = ft_extract_line(stash);
	stash = ft_clean_stash(stash);
	return (line);
}
