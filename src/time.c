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

void	ft_sleep(int	ms)
{
	while (1)
	{
		if (ft_get_time(ms) == 1)
			break;
	}
}

int	ft_get_time(int ms)
{
	struct timeval time;
	long long int seconds;
	long long int microseconds;
	// int diff;
	long long int actual;
	long long int	transcurrido;
	long long int	start;

	transcurrido = 0;
	start = 0;
	ms = ms * 1000;
	if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
		start = seconds + microseconds;
	}
	else
		printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");


	//printf("START == (%lli)\n", start);
	while (transcurrido <= ms)
	{
		//printf("TRANSCURRIDO == (%i)\n", transcurrido);
		if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
		{
			seconds = time.tv_sec * 1000000;
			microseconds = time.tv_usec;
			actual = seconds + microseconds;
			transcurrido = actual - start;
			//transcurrido = (time.tv_sec * 1000 + time.tv_usec / 1000) - start;
			//printf("\rACTUAL == (%lli), TRANSCURRIDO == (%lli)", actual, transcurrido / 1000);
			//printf("\rACTUAL == (%li), TRANSCURRIDO == (%lli)", time.tv_sec * 1000 + time.tv_usec / 1000, transcurrido);
			//printf("\rACTUAL == (%li), TRANSCURRIDO == (%lli)", (time.tv_sec * 1000 + time.tv_usec / 1000), transcurrido);
			if (transcurrido >= ms)
				break ;
			//printf("\rTRANSCURRIDO == (%i)", transcurrido);
		}
		else
			printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");
	}

	// (void)actual;
	// while (transcurrido <= ms)
	// {
	// 	usleep(10);
	// 	transcurrido = transcurrido + 10;
	// }
	return (1);
}


long long int	ft_actual_time()
{
	struct timeval time;
	long long int seconds;
	long long int microseconds;
	long long int actual;
	
	seconds = 0;
	microseconds = 0;
	if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
	}
	else
		printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");
	//printf("SECONDS == (%lld), MICROSECONDS == (%lld)\n", seconds, microseconds);
	actual = seconds + microseconds;
	//printf("ACTUAL == (%lld)\n", actual);
	return (actual); //Aqui trabajo con usec/microseconds

}

long long int	ft_diff_time(int time_start)
{
	struct timeval time;
	long long int seconds;
	long long int microseconds;
	long long int diff;
	long long int actual;
	
	seconds = 0;
	microseconds = 0;
	// while (1)
	// {
	// 	if (ft_get_time(500) == 1)
	// 		break;
	// }
	//printf("500 transcurridos\n");
	// exit(0);
	if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	{
		seconds = time.tv_sec * 1000000;
		microseconds = time.tv_usec;
		//printf("TIEMPO DE INICIO EN SEGUNDOS == (%li), + USEC == (%i)\n", time.tv_sec, test.time_start);
		// printf("ANYOS == (%i), DIAS == (%i), HORAS == (%i), MINUTOS == (%i)\n", (((seconds / 60) / 60 ) / 24) / 365 , ((seconds / 60) / 60 ) / 24 ,  (seconds / 60) / 60, seconds / 60);
		//printf("SECONDS == (%i), MICROSECONDS == (%i)\n", seconds, microseconds);
	}
	else
		printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");
	actual = seconds + microseconds;
	diff = actual - time_start;
	//printf("DIFF == (%lli) / 1000000 == (%lli)\n", diff, diff / 1000000);
	return (diff);
}
