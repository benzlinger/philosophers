/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:12:32 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/23 11:10:17 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_for_action(long time)
{
	long	start;

	start = gettime();
	while (gettime() < start + time)
		usleep(500);
	return ;
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->args->forks[philo->fork_left]));
	philo_action(philo->id, "has taken a fork\n", philo);
	pthread_mutex_lock(&(philo->args->forks[philo->fork_right]));
	philo_action(philo->id, "has taken a fork\n", philo);
	//philo->args->until_dead = gettime() + gettime();
	pthread_mutex_lock(&(philo->args->m_eat));
	philo_action(philo->id, "is eating\n", philo);
	philo->args->until_dead = gettime() + philo->args->d_time;
	pthread_mutex_unlock(&(philo->args->m_eat));
	wait_for_action(philo->args->e_time);
	//printf("philo: %d\n%ld\n%ld\n\n", philo->id, gettime(), philo->args->until_dead);
	philo->meals++;
	pthread_mutex_unlock(&(philo->args->forks[philo->fork_left]));
	pthread_mutex_unlock(&(philo->args->forks[philo->fork_right]));
}

void	my_sleep(t_philo *philo)
{
	if (philo->args->is_alive)
	{
		philo_action(philo->id, "is sleeping\n", philo);
		wait_for_action(philo->args->s_time);
	}
}

void	*exec_philos(void *philo_c)
{
	t_philo	*philo;

	philo = (t_philo *)philo_c;
	if (philo->id % 2)
		usleep(1000);
	while (philo->args->is_alive)
	{
		eat(philo);
		my_sleep(philo);
		philo_action(philo->id, "is thinking\n", philo);
	}
	return (0);
}
