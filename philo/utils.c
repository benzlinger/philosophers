/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:24:56 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/23 11:05:51 by btenzlin         ###   ########.fr       */
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

	if (philo->args->is_alive)
	{
		time = gettime() - philo->args->start;
		printf("%ld %d %s\n", time, id, msg);
	}
}

void	checker(t_philo *philos)
{
	int	count;
	int	full_philos;

	while (philos->args->is_alive)
	{
		count = 0;
		full_philos = 0;
		while (count < philos->args->p_num && philos->args->is_alive)
		{
			pthread_mutex_lock(&(philos->args->m_is_alive));
			if (gettime() >= philos[count].args->until_dead)
			{
				philo_action(philos[count].id, "died\n", &philos[count]);
				philos->args->is_alive = 0;
			}
			pthread_mutex_unlock(&(philos->args->m_is_alive));
			usleep(100);
			if (philos[count].meals >= philos->args->e_num)
				full_philos++;
			count++;
		}
		if (!philos->args->is_alive)
			break ;
		count = 0;
		while (count < philos->args->p_num)
		{
			pthread_join(philos[count].thread, NULL);
			count++;
		}
		// if (full_philos == philos->args->p_num)
			//end
	}
}
