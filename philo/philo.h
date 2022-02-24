/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:20:07 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/24 17:29:16 by btenzlin         ###   ########.fr       */
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

struct	s_args;

typedef struct s_philo
{
	pthread_t		thread;
	struct s_args	*args;
	int				id;
	int				meals;
	int				fork_left;
	int				fork_right;
	long			last_eat;
}					t_philo;

typedef struct s_args
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_is_alive;
	pthread_mutex_t	m_print;
	int				p_num;
	int				d_time;
	int				e_time;
	int				s_time;
	int				e_num;
	int				is_alive;
	int				philos_full;
	long			start;
}					t_args;

/* atoi */
long	ft_atoi(const char *str);

/* init */
int		check_input(char **argv);
t_args	*init_args(int argc, char **argv);
int		init_philos(t_args *args);
int		init_mutex(t_args *args);
int		create_philos(t_args *args);

/* utils */
long	gettime(void);
void	philo_action(int id, char *msg, t_philo *philo);
void	checker(t_args *args, t_philo *philos);
void	exiter(t_args *args);

/* exec */
void	*exec_philos(void *philo_c);

#endif