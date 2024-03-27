/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:33:05 by onault            #+#    #+#             */
/*   Updated: 2024/02/17 10:37:13 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tab;

	size = 0;
	if (s)
		size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (start + len > size && start < size)
		len = size - start;
	tab = malloc(len + 1);
	if (!tab || !s)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
