/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/07/07 16:28:13 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_sleep(int ms)
{
	while (1)
	{
		if (ft_get_time(ms) == 1)
			break ;
	}
}

int	ft_get_time(int ms)
{
	struct timeval	time;
	long long int	seconds;
	long long int	microseconds;
	long long int	actual;
	long long int	transcurrido;
	long long int	start;

	transcurrido = 0;
	start = 0;
	ms = ms * 1000;
	if (gettimeofday(&time, NULL) == 0)
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
		start = seconds + microseconds;
	}
	while (transcurrido <= ms)
	{
		if (gettimeofday(&time, NULL) == 0)
		{
			seconds = time.tv_sec * 1000000;
			microseconds = time.tv_usec;
			actual = seconds + microseconds;
			transcurrido = actual - start;
			if (transcurrido >= ms)
				break ;
		}
	}
	return (1);
}

long long int	ft_actual_time(void)
{
	struct	timeval	time;
	long long int	seconds;
	long long int	microseconds;
	long long int	actual;
	
	seconds = 0;
	microseconds = 0;
	if (gettimeofday(&time, NULL) == 0)
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
	}
	actual = seconds + microseconds;
	return (actual); //Aqui trabajo con usec/microseconds

}

long long int	ft_diff_time(int time_start)
{
	struct			timeval time;
	long long int	seconds;
	long long int	microseconds;
	long long int	diff;
	long long int	actual;

	seconds = 0;
	microseconds = 0;
	if (gettimeofday(&time, NULL) == 0)
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
	}
	actual = seconds + microseconds;
	diff = actual - time_start;
	return (diff);
}
