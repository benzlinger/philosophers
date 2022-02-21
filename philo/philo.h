/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:20:07 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/21 17:32:53 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t	thread;
	t_args		args;
	int			id;
	int			meals;
	int			fork_left;
	int			fork_right;
}				t_philo;

typedef struct s_args
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				p_num;
	int				d_time;
	int				e_time;
	int				s_time;
	int				e_num;
}					t_args;

/* atoi */
long	ft_atoi(const char *str);

/* init */
int		check_input(char **argv);
t_args	*init_args(int argc, char **argv);
int		init_philos(t_args *args);
int		create_philos(t_args *args);

#endif