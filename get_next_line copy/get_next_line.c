/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:34:02 by onault            #+#    #+#             */
/*   Updated: 2024/02/27 13:49:55 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del_line(char **storage)
{
	char	*temp;

	temp = ft_strchr(*storage, '\n');
	if (!temp || temp[0] == '\0')
		temp = NULL;
	else
	{
		temp = ft_strdup(++temp);
		if (!temp)
		{
			free(*storage);
			*storage = NULL;
			return ;
		}
	}
	free(*storage);
	*storage = temp;
}

char	*insert_into_storage(char *buffer, char **storage)
{
	char	*s;

	if (!*storage)
		*storage = ft_strdup(buffer);
	else
	{
		s = ft_strjoin(*storage, buffer);
		if (!s)
		{
			free(*storage);
			return (NULL);
		}
		free(*storage);
		*storage = s;
	}
	return (*storage);
}

void	read_file_insert(int fd, char **storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		r;
	char	*s;

	r = BUFFER_SIZE;
	while (r > 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == 0)
			break ;
		if (r < 0 || !r)
		{
			free(*storage);
			*storage = NULL;
			break ;
		}
		buffer[r] = '\0';
		if (!insert_into_storage(buffer, storage))
			break ;
		s = ft_strchr(buffer, '\n');
		if (s)
			break ;
	}
}

char	*read_line(char **storage)
{
	char	*line;
	char	*n_pos;
	int		length;

	line = NULL;
	n_pos = NULL;
	length = 0;
	n_pos = ft_strchr(*storage, '\n');
	if (n_pos)
	{
		length = n_pos - *storage;
		line = malloc(length + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, *storage, length + 2);
	}
	else
	{
		length = ft_strlen(*storage);
		line = malloc(length + 2);
		if (!line)
			return (NULL);
		ft_strlcpy(line, *storage, length + 2);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file_insert(fd, &storage);
	if (!storage || *storage == '\0')
	{
		free(storage);
		return (NULL);
	}
	s = read_line(&storage);
	del_line(&storage);
	return (s);
}
