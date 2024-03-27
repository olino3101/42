/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:17:15 by onault            #+#    #+#             */
/*   Updated: 2024/02/14 13:53:14 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*p;
	unsigned char	q;

	q = c;
	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = q;
		len--;
	}
	return (b);
}
