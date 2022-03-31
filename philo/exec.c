/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:12:32 by btenzlin          #+#    #+#             */
/*   Updated: 2022/03/31 14:10:10 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->forks[philo->fork_left]);
	philo_action(philo->id, "has taken a fork", philo);
	pthread_mutex_lock(&philo->args->forks[philo->fork_right]);
	philo_action(philo->id, "has taken a fork", philo);
	pthread_mutex_lock(&philo->args->m_is_alive);
	philo_action(philo->id, "is eating", philo);
	philo->last_eat = gettime();
	pthread_mutex_unlock(&philo->args->m_is_alive);
	wait_for_action(philo->args->e_time, philo->args);
	philo->meals++;
	pthread_mutex_unlock(&philo->args->forks[philo->fork_left]);
	pthread_mutex_unlock(&philo->args->forks[philo->fork_right]);
}

static void	my_sleep(t_philo *philo)
{
	if (philo->args->is_alive)
	{
		philo_action(philo->id, "is sleeping", philo);
		wait_for_action(philo->args->s_time, philo->args);
	}
}

void	*exec_philos(void *philo_c)
{
	t_philo	*philo;

	philo = (t_philo *)philo_c;
	if (philo->args->p_num == 1)
		return (0);
	if (philo->id % 2)
		usleep(philo->args->e_time * 1000);
	while (philo->args->is_alive)
	{
		eat(philo);
		my_sleep(philo);
		if (philo->args->is_alive)
			philo_action(philo->id, "is thinking", philo);
	}
	return (0);
}
