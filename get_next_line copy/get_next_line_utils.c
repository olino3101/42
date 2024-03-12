/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:19:27 by onault            #+#    #+#             */
/*   Updated: 2024/02/29 11:21:27 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		tab[i] = s2[len];
		i++;
		len++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (&ptr[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&ptr[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < size)
		{
			dest[index] = src[index];
			if (src[index] == '\0')
				return (index);
			index++;
		}
		index--;
		dest[index] = '\0';
	}
	index = 0;
	while (src[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(const char *s1)
{
	char	*target;
	int		i;

	if (*s1 == '\0')
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
		i++;
	target = malloc(i + 1);
	if (!target)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		target[i] = s1[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
