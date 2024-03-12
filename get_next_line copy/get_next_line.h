/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:32:12 by onault            #+#    #+#             */
/*   Updated: 2024/02/27 12:50:45 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *s1);
void	read_file_insert(int fd, char **storage);
char	*insert_into_storage(char *buffer, char **storage);
void	del_line(char **storage);

#endif