/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/07/21 15:18:38 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_first_value(t_master *master, char **argv)
{
	// struct timeval time;
	// int	seconds;
	// int	microseconds;

	master->number_philo = ft_atoi(argv[1]);
	master->time_dead = ft_atoi(argv[2]);
	master->time_eat = ft_atoi(argv[3]);
	master->time_sleep = ft_atoi(argv[4]);
	master->start = 0;
	if (master->argc == 5)
		master->will_eat = ft_atoi(argv[5]);
	else
		master->will_eat = -1;
	// if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	// {
	// 	master->time_start = time.tv_usec; //tv_sec --> Segundos && tv_usec --> Microsegundos
	// 	seconds = time.tv_sec;
	// 	microseconds = time.tv_usec;
	// 	printf("ANYOS == (%i), DIAS == (%i), HORAS == (%i), MINUTOS == (%i)\n", (((seconds / 60) / 60 ) / 24) / 365 , ((seconds / 60) / 60 ) / 24 ,  (seconds / 60) / 60, seconds / 60);
	// 	printf("SECONDS == (%i), MICROSECONDS == (%i)\n", seconds, microseconds);
	// }
	// else
	// 	printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");
	// printf("TIME == (%i)\n", master->time_start);
}

int	main(int argc, char **argv)
{
	t_master	master;
	
	argc = argc - 1;
	master.argc = argc;


	if (argc <= 3 || argc >= 6)
	{
		printf("ERROR EN NUMERO DE ARGUMENTOS\n");
		return (0);
	}
	else
	{
		if (ft_check_argv(argv) == 1)
		{
			printf("ERROR CON UN ARGUMENTO\n");
			return (0);
		}
	}
	// while (1)
	// {
	// 	if (ft_get_time(500) == 1)
	// 		break;
	// }
	// printf("\n500 transcurridos\n");
	// exit(0);

	// printf("RECIBIENDO (%i) ARGUMENTOS\n", argc);
	// printf("NUMERO DE FILOSOFOS == (%s)\n", argv[1]);
	// printf("TIEMPO PARA MORIR == (%s)\n", argv[2]);
	// printf("TIEMPO PARA COMER == (%s)\n", argv[3]);
	// printf("TIEMPO PARA DORMIR == (%s)\n", argv[4]);
	// printf("*OPCIONAL* VECES QUE VA A COMER == (%s)\n", argv[5]);
	ft_first_value(&master, argv); // Le doy valor a la estructura
	if (argc == 4)
	{
		printf("CASO NORMAL\n");
		// printf("INICIANDO CON == (%i)\n", master.time_start);
		// pthread_t h1 ;
		// pthread_t h2 ;
		// int	r;
		// printf("DIR MASTER == (%p)\n", &master);
		// r = pthread_create(&h1 , NULL , hola, (void *)&master); //Retorna 0 cuando no hay error
		// printf("R (h1) == (%d)\n", r);
		// r = pthread_create(&h2 , NULL , mundo, (void *)&master);
		// printf("R (h2) == (%d)\n", r);
		// r = pthread_join(h1, NULL); //Retorna 0 cuando no hay error, ESPERA A QUE TERMINE EL PROCESO
		// printf("FINAL R-join (h1) == (%d)\n", r);
	}
	else if (master.argc == 5)
	{
		printf("CASO PECULIAR\n");
	}
	ft_create_childs(&master);
	return (0);
}

/* 
Falta obtener el identificador del hilo


Esta es la version que tenia en mi casa



OJO:
*	Enviarme menos datos a los hijos, una mini estructura con los datos necesarios.

TO DO:
*	Hacer todos los tenedores



*/