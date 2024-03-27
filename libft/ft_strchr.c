/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:53:21 by onault            #+#    #+#             */
/*   Updated: 2024/02/14 13:54:19 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
