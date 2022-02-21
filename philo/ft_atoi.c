/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:46:41 by btenzlin          #+#    #+#             */
/*   Updated: 2022/02/18 10:33:16 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	int		count;
	int		isnegative;
	long	result;

	count = 0;
	result = 0;
	isnegative = 1;
	while (str[count] == '\n' || str[count] == '\v' || str[count] == '\t'
		|| str[count] == '\r' || str[count] == '\f' || str[count] == ' ')
		count++;
	if (str[count] == '-')
	{
		count++;
		isnegative = -1;
	}	
	else if (str[count] == '+')
		count++;
	while (str[count] != '\0')
	{
		if (!ft_isdigit(str[count]))
			return (0);
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * isnegative);
}
