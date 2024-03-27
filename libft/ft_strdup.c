/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:00:49 by onault            #+#    #+#             */
/*   Updated: 2024/02/16 15:49:22 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*target;
	int		i;

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
