/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:18:03 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/24 17:00:02 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_error(void)
{
	printf("Please enter the following 4 (or 5) arguments:\n");
	printf("Each of these arguments should be positive integers\n");
	printf("1: Number of philosophers\n");
	printf("2: Time to die\n");
	printf("3: Time to eat\n");
	printf("4: Time to sleep\n");
	printf("5: Number of times each philosopher should eat (optional)\n");
}

int	main(int argc, char **argv)
{
	t_args	*args;

	if (argc != 5 && argc != 6)
	{
		input_error();
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
