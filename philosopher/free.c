/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:43:39 by onault            #+#    #+#             */
/*   Updated: 2024/06/05 17:19:44 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*try_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	free_everything(t_philo **philo, t_data *data, pthread_t **thread)
{
	int	size;
	int	i;

	size = data->nb_of_philo;
	i = 0;
	while (i != size)
	{
		pthread_mutex_destroy(philo[i]->right->lock);
		try_free(thread[i]);
		try_free(philo[i]->right->lock);
		try_free(philo[i]->right);
		try_free(philo[i]);
		i++;
	}
	try_free(thread);
	try_free(philo);
	pthread_mutex_destroy(data->lock);
	pthread_mutex_destroy(data->print);
	try_free(data->lock);
	try_free(data->print);
}
