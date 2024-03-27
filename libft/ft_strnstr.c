/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:32:41 by onault            #+#    #+#             */
/*   Updated: 2024/02/17 15:59:16 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ifind;

	i = 0;
	ifind = 0;
	if (haystack == 0)
		return (0);
	if (needle == 0 || needle[0] == '\0')
		return ((char *)haystack);
	while ((i < len || len == (size_t)-1) && haystack[i] != '\0')
	{
		if (haystack[i] == needle[ifind])
		{
			while (haystack[i + ifind] == needle[ifind] && i + ifind < len)
			{
				ifind++;
				if (needle[ifind] == '\0')
					return ((char *)haystack + i);
			}
			ifind = 0;
		}
		i++;
	}
	return (NULL);
}
