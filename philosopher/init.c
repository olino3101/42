/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:40:56 by onault            #+#    #+#             */
/*   Updated: 2024/06/05 13:28:01 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_memcpy(void *src, void *dest, size_t size)
{
	if (!src || !dest)
		return ;
	while (size--)
		((unsigned char *)dest)[size] = ((unsigned char *)src)[size];
}

static void	set_data(t_philo **new, t_data *data, int i)
{
	new[i]->id = i + 1;
	new[i]->meal = 0;
	ft_memcpy(data, &new[i]->info, sizeof(t_data));
}

bool	init_thread(pthread_t ***thread, int size)
{
	pthread_t	**new;
	int			i;

	i = 0;
	new = ft_calloc(size + 1, sizeof(pthread_t *));
	if (!new)
		return (false);
	while (i != size)
	{
		new[i] = ft_calloc(1, sizeof(pthread_t));
		if (!new[i])
			return (false);
		i++;
	}
	*thread = new;
	return (true);
}

void	init_take_left(t_philo **philo)
{
	int	i;

	i = 1;
	pthread_mutex_init(philo[0]->right->lock, NULL);
	while (i != philo[0]->info.nb_of_philo)
	{
		pthread_mutex_init(philo[i]->right->lock, NULL);
		philo[i]->left = philo[i - 1]->right;
		i++;
	}
	philo[0]->left = philo[philo[0]->info.nb_of_philo - 1]->right;
}

bool	init_philo(t_philo ***philo, t_data *data)
{
	t_philo	**new;
	int		i;

	new = ft_calloc(data->nb_of_philo + 1, sizeof(t_philo *));
	if (!new)
		return (false);
	i = 0;
	while (i != data->nb_of_philo)
	{
		new[i] = ft_calloc(1, sizeof(t_philo));
		if (!new[i])
			return (false);
		new[i]->right = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!new[i]->right)
			return (false);
		new[i]->right->lock = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!new[i]->right->lock)
			return (false);
		set_data(new, data, i);
		i++;
	}
	init_take_left(new);
	*philo = new;
	return (true);
}
