/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:03 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/22 13:05:04 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc != 5 && argc != 6)
	{
		printf("Input error\n");
		printf("Arguments: philos die_time eat_time sleep_time [eat_amount]\n");
		return (-1);
	}
	if (!check_input(argv))
		return (-1);
	args = init_args(argc, argv);
	if (!args)
		return (-1);
	if (!create_philos(args))
		return (-1);
	//system("leaks philo");
	//TODO: free(philos, forks, (destroy)mutexes, args)!!!
	return (0);
}
