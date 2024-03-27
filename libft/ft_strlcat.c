/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:25:14 by onault            #+#    #+#             */
/*   Updated: 2024/02/15 17:56:39 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dest;
	size_t	i_src;

	i_dest = 0;
	while (i_dest != dstsize && dst[i_dest] != '\0')
		i_dest++;
	i_src = 0;
	while (src[i_src] != '\0' && i_dest + 1 < dstsize)
	{
		dst[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	if (i_dest < dstsize)
		dst[i_dest] = '\0';
	while (src[i_src])
	{
		i_dest++;
		i_src++;
	}
	return (i_dest);
}
