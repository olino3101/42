/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:32:51 by onault            #+#    #+#             */
/*   Updated: 2024/06/11 15:57:39 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	static struct timeval	start = {-1, -1};
	struct timeval			now;

	if (start.tv_sec == -1 && start.tv_usec == -1)
		gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000 - start.tv_sec * 1000) + \
	(now.tv_usec / 1000 - start.tv_usec / 1000));
}

bool	can_take_fork(t_philo *philo)
{
	t_data	*shared_data;
	bool	use;

	shared_data = return_data(NULL);
	pthread_mutex_lock(shared_data->lock);
	if (philo->left->use == 0 && philo->right->use == 0)
	{
		philo->left->use = 1;
		philo->right->use = 1;
		use = true;
	}
	else
		use = false;
	pthread_mutex_unlock(shared_data->lock);
	return (use);
}

void	give_back_fork(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(data->lock);
	philo->left->use = 0;
	philo->right->use = 0;
	pthread_mutex_unlock(data->lock);
	pthread_mutex_unlock(philo->left->lock);
	pthread_mutex_unlock(philo->right->lock);
}

bool	print(int f, short id)
{
	t_data	*data;
	bool	err;

	data = return_data(NULL);
	pthread_mutex_lock(data->lock);
	if (data->is_dead == false)
	{
		if (f == 0)
			printf(COLOR_THINK"\U0001F4A1 %lli %i %s\n", get_time(), id, THINK);
		if (f == 1)
			printf(COLOR_SLEEP"\U0001F634 %lli %i %s\n", get_time(), id, SLEEP);
		if (f == 2)
			printf(COLOR_EAT"\U0001F35D %lli %i %s\n", get_time(), id, EAT);
		if (f == 3)
			printf(COLOR_FORK"\U0001F374 %lli %i %s\n", get_time(), id, TAKE);
		if (f == 4)
			printf(COLOR_DIED"\U0001F480 %lli %i %s\n", get_time(), id, DIE);
		err = true;
	}
	else
		err = false;
	pthread_mutex_unlock(data->lock);
	return (err);
}

void	is_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(data->lock);
	if (data->is_dead == false)
	{
		pthread_mutex_unlock(data->lock);
		print(4, philo->id);
		pthread_mutex_lock(data->lock);
		data->is_dead = true;
		pthread_mutex_unlock(data->lock);
	}
	pthread_mutex_unlock(data->lock);
}
