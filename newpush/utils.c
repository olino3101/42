/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:05:21 by onault            #+#    #+#             */
/*   Updated: 2024/03/25 16:08:20 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]
			|| s1[i] == '\0')
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	nb;

	i = 0;
	nb = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * minus);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_sorted(t_col *cola)
{
	int	i;

	i = 0;
	while (i != *cola->sizeofc - 1)
	{
		if (cola->c[i] > cola->c[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	free_col(t_col *cola, t_col *colb)
{
	free(cola->sizeofc);
	free(colb->sizeofc);
	free(cola->c);
	free(colb->c);
	free(cola);
	free(colb);
}
