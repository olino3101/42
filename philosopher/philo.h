/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:31:01 by onault            #+#    #+#             */
/*   Updated: 2024/06/05 15:33:16 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
// do all the defines
# define DIE "died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define TAKE "has taken a fork"
# define COLOR_FORK "\033[32m"
# define COLOR "\033[3m \033[4m \033[29m"
# define COLOR_SLEEP "\033[34m"
# define COLOR_EAT "\033[35m"
# define COLOR_THINK "\033[36m"
# define COLOR_DIED "\033[31m"

typedef long long	t_time;

typedef struct s_data
{
	t_time			t_toeat;
	t_time			t_todie;
	t_time			t_tosleep;
	pthread_mutex_t	*print;
	pthread_mutex_t	*lock;
	bool			is_dead;
	int				nb_of_philo;
	int				meal_need;
}	t_data;

typedef struct s_fork
{
	pthread_mutex_t	*lock;
	int				use;
}	t_fork;

typedef struct s_philo
{
	int		id;
	int		meal;
	t_data	info;
	t_fork	*left;
	t_fork	*right;
	t_time	last_meal;
}	t_philo;

void	free_everything(t_philo **philo, t_data *data, pthread_t **thread);
bool	check_arg(char *argv[], int argc);
bool	insert_arg_to_data(t_data *data, char *argv[], int argc);
void	*ft_calloc(size_t count, size_t size);
bool	init_thread(pthread_t ***thread, int size);
bool	init_philo(t_philo ***philo, t_data *data);
void	init_take_left(t_philo **philo);
void	*try_free(void *ptr);
t_time	get_time(void);
void	*return_data(void *ptr);
bool	can_take_fork(t_philo *philo);
void	give_back_fork(t_philo *philo, t_data *data);
bool	print(int f, short id);
void	is_dead(t_philo *philo, t_data *data);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_calloc(size_t count, size_t size);

#endif