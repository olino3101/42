/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:43:37 by onault            #+#    #+#             */
/*   Updated: 2024/06/11 15:59:13 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	eat(t_philo *philo)
{
	t_time	t_eat;

	t_eat = philo->info.t_toeat + get_time();
	philo->last_meal = philo->info.t_todie + get_time();
	philo->meal++;
	print(2, philo->id);
	while (t_eat > get_time())
	{
		if (get_time() > philo->last_meal)
		{
			is_dead(philo, return_data(NULL));
			return (false);
		}
		usleep(100);
	}
	give_back_fork(philo, return_data(NULL));
	return (true);
}

bool	think(t_philo *philo)
{
	print(0, philo->id);
	usleep(1000);
	while (can_take_fork(philo) == false)
	{
		if (get_time() > philo->last_meal)
		{
			is_dead(philo, return_data(NULL));
			return (false);
		}
		usleep(100);
	}
	pthread_mutex_lock(philo->right->lock);
	if (print(3, philo->id) == false)
		return (false);
	if (philo->info.nb_of_philo == 1)
	{
		while (get_time() < philo->info.t_todie)
			usleep(100);
		is_dead(philo, return_data(NULL));
		return (false);
	}
	pthread_mutex_lock(philo->left->lock);
	if (print(3, philo->id) == false)
		return (false);
	return (true);
}

bool	sleep_zzz(t_philo *philo)
{
	t_time	t_sleep;

	print(1, philo->id);
	t_sleep = get_time() + philo->info.t_tosleep;
	while (t_sleep > get_time())
	{
		if (philo->last_meal < get_time())
		{
			is_dead(philo, return_data(NULL));
			return (false);
		}
		usleep(100);
	}
	return (true);
}

void	*routine(void *var)
{
	t_philo		*philo;

	philo = (t_philo *)var;
	philo->last_meal = philo->info.t_todie;
	if (philo->id % 2 == 0)
		usleep(philo->info.t_toeat * 10);
	while (philo->meal < philo->info.meal_need || !philo->info.meal_need)
	{
		if (think(philo) == false)
			break ;
		if (eat(philo) == false)
			break ;
		if (sleep_zzz(philo) == false)
			break ;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_philo		**philo;
	pthread_t	**thread;
	int			i;
	int			size;

	thread = NULL;
	philo = NULL;
	if (!check_arg(argv, argc) || !insert_arg_to_data(&data, argv, argc))
		return (1);
	if (!init_philo(&philo, &data) || !init_thread(&thread, data.nb_of_philo))
	{
		free_everything(philo, &data, thread);
		return (1);
	}
	printf(COLOR);
	i = -1;
	size = data.nb_of_philo;
	while (++i != data.nb_of_philo)
		pthread_create(thread[i], NULL, &routine, philo[i]);
	while (--size != -1)
		pthread_join(*thread[size], NULL);
	free_everything(philo, &data, thread);
}
