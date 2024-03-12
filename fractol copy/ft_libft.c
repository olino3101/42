/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:03:58 by onault            #+#    #+#             */
/*   Updated: 2024/03/12 15:39:36 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factal.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]
			|| s1[i] == '\0')
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

static float	ft_atoi_number(const char *str, int i)
{
	float	nb;
	bool	yes_virgule;
	int		virgule;

	virgule = 0;
	nb = 0;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] == '.'))
	{
		if (str[i] == '.')
			yes_virgule = true;
		else
			nb = nb * 10 + (str[i] - 48);
		if (yes_virgule == true)
			virgule++;
		i++;
	}
	while (--virgule > 0)
		nb /= 10;
	return (nb);
}

float	ft_atoi(const char *str)
{
	int		i;
	int		minus;

	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	return (ft_atoi_number(str, i) * minus);
}
