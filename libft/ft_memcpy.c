/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:00:25 by onault            #+#    #+#             */
/*   Updated: 2024/02/16 16:09:40 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dstt;
	char	*srcc;
	size_t	i;

	if (n == 0)
		return (dest);
	if (!dest || !src)
		return (NULL);
	dstt = (char *)dest;
	srcc = (char *)src;
	i = 0;
	while (i != n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dest);
}
