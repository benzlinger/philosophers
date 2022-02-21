/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:15:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/21 17:44:58 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_input(char **argv)
{
	int		count;
	long	num;

	count = 1;
	while (argv[count])
	{
		num = ft_atoi(argv[count]);
		if (num < 0 || num > INT_MAX)
		{
			printf("Error\nArguments should be positive integers\n");
			return (0);
		}
		count++;
	}
	return (1);
}

t_args	*init_args(int argc, char **argv)
{
	t_args	*args;

	args = malloc(sizeof(t_args) * argc - 1);
	if (!args)
		return (0);
	args->p_num = ft_atoi(argv[1]);
	args->d_time = ft_atoi(argv[2]);
	args->e_time = ft_atoi(argv[3]);
	args->s_time = ft_atoi(argv[4]);
	if (args->p_num <= 1 || args->p_num > 200)
		return (0);
	if (argc == 6)
	{
		args->e_num = ft_atoi(argv[5]);
		if (args->e_num <= 0)
			return (0);
	}
	else
		args->e_num = -1;
	return (args);
}

int	init_philos(t_args *args)
{
	int	count;

	args->philos = malloc(sizeof(t_philo) * args->p_num);
	if (!args->philos)
		return (0);
	count = 0;
	while (count < args->p_num)
	{
		args->philos[count].id = count;
		args->philos[count].meals = 0;
		args->philos[count].args = args;
		args->philos[count].fork_left = count;
		if ((count + 1) < args->p_num)
			args->philos[count].fork_right = count + 1;
		else
			args->philos[count].fork_right = 0;
		count++;
	}
	return (1);
}

int	init_mutex(t_args *args)
{
	int	count;

	args->forks = malloc(sizeof(t_philo) * args->p_num);
	if (!args->forks)
		return (0);
	count = 0;
	while (count < args->p_num)
	{
		if (pthread_mutex_init(&args->forks[count], NULL))
			return (0);
		count++;
	}
	return (1);
}

void	*exec_philos(void *philo_c)
{
	t_philo	*philo;
	t_args	*args;

	philo = (t_philo *)philo_c;
	args = philo->args;
}

int	create_philos(t_args *args)
{
	int			count;

	if (!init_philos(args))
		return (0);
	count = 0;
	while (count < args->p_num)
	{
		pthread_create(&(args->philos[count].thread),
			NULL, exec_philos, &(args->philos[count]));
		count++;
	}
	count = 0;
	while (count < args->p_num)
	{
		pthread_join(args->philos[count].thread, NULL);
		count++;
	}
	free(args->forks);
	free(args->philos);
	return (1);
}
