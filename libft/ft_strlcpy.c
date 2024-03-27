/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:13:28 by onault            #+#    #+#             */
/*   Updated: 2024/02/14 13:55:46 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
