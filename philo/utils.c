/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:24:56 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/24 15:34:17 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	return ((timeval.tv_sec * 1000) + (timeval.tv_usec / 1000));
}

void	philo_action(int id, char *msg, t_philo *philo)
{
	long	time;

	pthread_mutex_lock(&philo->args->m_print);
	if (philo->args->is_alive)
	{
		time = gettime() - philo->args->start;
		printf("%ld %d %s\n", time, id, msg);
	}
	pthread_mutex_unlock(&philo->args->m_print);
}

// void	checker(t_args *args, t_philo *philos)
// {
// 	int	count;

// 	while (!args->philos_full)
// 	{
// 		count = 0;
// 		while (args->is_alive && count < args->p_num)
// 		{
// 			pthread_mutex_lock(&(args->m_is_alive));
// 			if (gettime() >= philos[count].last_eat + args->d_time)
// 			{
// 				philo_action(philos[count].id, "died", philos);
// 				args->is_alive = 0;
// 			}
// 			count++;
// 			pthread_mutex_unlock(&(args->m_is_alive));
// 		}
// 		if (!args->is_alive)
// 			break ;
// 		count = 0;
// 		while (args->e_num >= 0 && count < args->p_num
// 			&& philos[count].meals >= args->e_num)
// 			count++;
// 		if (count == args->p_num)
// 			args->philos_full = 1;
// 	}
// }

void	checker(t_args *args, t_philo *philos)
{
	int	count;

	while (args->is_alive)
	{
		count = 0;
		pthread_mutex_lock(&args->m_is_alive);
		while (count < args->p_num && args->is_alive)
		{
			if (gettime() >= philos[count].last_eat + args->d_time)
			{
				philo_action(philos[count].id, "died", philos);
				args->is_alive = 0;
			}
			else if (args->e_num > 0 && philos[count].meals >= args->e_num)
				args->philos_full++;
			count++;
		}
		if (args->philos_full >= args->p_num)
			args->is_alive = 0;
		pthread_mutex_unlock(&args->m_is_alive);
	}
}

void	exiter(t_args *args)
{
	int		count;
	t_philo	*philos;

	count = 0;
	philos = args->philos;
	while (count < args->p_num)
	{
		pthread_join(philos[count].thread, NULL);
		count++;
	}
	pthread_mutex_destroy(&args->m_print);
	pthread_mutex_destroy(&args->m_is_alive);
	pthread_mutex_destroy(&args->m_meals);
	count = 0;
	while (count < args->p_num)
	{
		pthread_mutex_destroy(&args->forks[count]);
		count++;
	}
	free(args->forks);
	free(args->philos);
	free(args);
}
