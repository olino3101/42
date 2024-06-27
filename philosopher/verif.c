/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:48:13 by onault            #+#    #+#             */
/*   Updated: 2024/06/05 17:17:54 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_no_nbrs(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit((int)s[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

bool	check_arg(char *argv[], int argc)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		perror("wrong number of argument");
		return (false);
	}
	if (argv[1][0] == '0' && argv[1][1] == '\0')
	{
		perror("no philosophers at the table");
		return (false);
	}
	while (i != argc)
	{
		if (check_no_nbrs(argv[i]) == false)
		{
			perror("wrong argument");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	mutex_data(t_data *data)
{
	data->lock = ft_calloc(1, sizeof(pthread_mutex_t));
	data->print = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->print || !data->lock)
	{
		try_free(data->print);
		try_free(data->lock);
		return (false);
	}
	pthread_mutex_init(data->lock, NULL);
	pthread_mutex_init(data->print, NULL);
	return (true);
}

bool	insert_arg_to_data(t_data *data, char *argv[], int argc)
{
	data->nb_of_philo = ft_atoi(argv[1]);
	if (data->nb_of_philo > 200)
	{
		perror("wrong argument");
		return (false);
	}
	data->t_todie = ft_atoi(argv[2]);
	data->t_toeat = ft_atoi(argv[3]);
	data->t_tosleep = ft_atoi(argv[4]);
	data->is_dead = false;
	if (argc == 6)
		data->meal_need = ft_atoi(argv[5]);
	if (mutex_data(data) == false)
		return (false);
	return_data(data);
	return (true);
}
