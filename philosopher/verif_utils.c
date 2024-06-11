/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:21:56 by onault            #+#    #+#             */
/*   Updated: 2024/06/05 17:17:56 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

static void	ft_bzero(void *ptr, size_t size)
{
	if (!ptr)
		return ;
	while (size--)
		((char *)ptr)[size] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = NULL;
	new = malloc(count * size);
	if (!new)
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}

void	*return_data(void *ptr)
{
	static void	*memory = NULL;

	if (ptr)
		memory = ptr;
	return (memory);
}
