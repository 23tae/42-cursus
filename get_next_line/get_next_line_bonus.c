/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:21:17 by taehooki          #+#    #+#             */
/*   Updated: 2022/06/06 18:35:20 by taehooki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_save_rest(char *backup)
{
	char	*rest;
	int		idx1;
	int		idx2;

	idx1 = 0;
	idx2 = 0;
	while (backup[idx1] && backup[idx1] != '\n')
		++idx1;
	if (!backup[idx1])
	{
		free(backup);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(backup) - idx1 + 1));
	if (!rest)
		return (NULL);
	++idx1;
	while (backup[idx1])
		rest[idx2++] = backup[idx1++];
	rest[idx2] = '\0';
	free(backup);
	return (rest);
}

static char	*ft_extract_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	if (!backup[i])
		return (NULL);
	while (backup[i] && backup[i] != '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		++i;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_read_data(int fd, char *backup)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX + 1];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = ft_read_data(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = ft_extract_line(backup[fd]);
	backup[fd] = ft_save_rest(backup[fd]);
	return (line);
}
