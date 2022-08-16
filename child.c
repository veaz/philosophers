/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/07/21 15:20:18 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_childs(t_master *master) //Sex function
{
	struct timeval time;
	pthread_t *childs;
	int	seconds;
	int	microseconds;
	// pthread_t h1[4];

	t_master test;
	test = *master; // SE CASTEA SOLO PARA ENVIAR A LOS HIJOS
	
	int	x;

	x = 0;
	printf("FT_CREATE_CHILDS\n");
	// printf("h-TIME MAIN == (%i)\n", master->time_start);
	childs = (pthread_t *)malloc(master->number_philo + 1);
	// if (pthread_create(&h1[x], NULL , ft_hola, (void *)&test) == 0)
	// 	printf("CHILD [1] CREATE\n");
	// pthread_join(h1[x], NULL);

	// if (pthread_create(&childs[x], NULL , ft_child, (void *)&test) == 0) //FUNCIONAL
	// 	printf("CHILD [1] CREATE\n");
	// test.start = 1;
	// printf("START NOW == (%i)\n", test.start);
	// pthread_join(childs[x], NULL);

	// if (pthread_create(&childs[x], NULL , ft_child, (void *)&master) == 0) // CRISIS EXISTENCIAL ACERCA DE ENVIAR *STRUCT O STRUCT SIN PUNTERO
	// 	printf("CHILD [1] CREATE\n");
	// master->start = 1;
	// printf("START NOW == (%i)\n", master->start);
	// pthread_join(childs[x], NULL);

	test.childs = 0;
	while (x < master->number_philo)
	{
		if (pthread_create(&childs[x] , NULL , ft_child, (void *)&test) == 0)
			x++;
		else
			printf("UPS! ERROR HAVING SEX, PLEASE DONT USE CONDON, WE NEED CHILDS\n");
		test.childs++;
	}
	// printf("HIJOS CREADOS == (%i)\n", x);
	

	if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	{
		test.time_start = time.tv_sec; //tv_sec --> Segundos && tv_usec --> Microsegundos
		seconds = time.tv_sec;
		microseconds = time.tv_usec;
		test.time_start = (time.tv_sec * 1000000) + time.tv_usec;
		//printf("TIEMPO DE INICIO EN SEGUNDOS == (%li), + USEC == (%i)\n", time.tv_sec, test.time_start);
		// printf("ANYOS == (%i), DIAS == (%i), HORAS == (%i), MINUTOS == (%i)\n", (((seconds / 60) / 60 ) / 24) / 365 , ((seconds / 60) / 60 ) / 24 ,  (seconds / 60) / 60, seconds / 60);
		// printf("SECONDS == (%i), MICROSECONDS == (%i)\n", seconds, microseconds);
	}
	else
		printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");

	//usleep(2000);

	test.start = 1; // INICIO TODOS LOS HIJOS
	//printf("START NOW == (%i)\n", test.start);
	// usleep(5000);
	x = 0;
	while (1)
	{
		if (pthread_join(childs[x], NULL) == 0)
			x++;
		if (x == master->number_philo)
			break;
	}
	printf("\nESPERA PERFECTA\n");

	// pthread_join(childs[0], NULL); //ESPERO A QUE TERMINE CADA UNO
	// pthread_join(childs[1], NULL);
	// pthread_join(childs[2], NULL);
	// x = pthread_join(childs[3], NULL);
	// printf("MAIN: X == (%i)\n", x);
}





void *ft_child(void *master)
{
	//struct timeval time;
	t_master *m;
	long long int diff;
	int me;
	int	type_of_child;

	m = (t_master *)master;
	//printf("H: SOY EL HIJO #(%i) CREADO\n", m->childs);
	me = m->childs;
	type_of_child = 0;
	//ft_print_message("SOY UN HIJO");
	// printf("h-TIME == (%i)\n", m->time_start);
	while (1)
	{
		if (m->start == 1) // Espero a que se creen todos e inicio
			break;
	}
	diff = 0;
	ft_print_message(diff, me, "has taken a fork");
	// while (1)
	// {
	// 	if (ft_get_time(200) == 1)
	// 		break;
	// }
	//ft_sleep(50);

	if ((me + 1) % 2 != 0)
	{
		printf("SOY #(%i) Y SOY TIPO 1\n", me + 1);
		type_of_child = 1;
	}
	// else
	// 	printf("SOY #(%i) Y NO ME INTERESA MAS\n", me + 1);

	if (pthread_mutex_lock(&m->mutex) == 0)
	{
		printf("CHILD BLOCK GOOD BYE\n");
		return NULL;
		//exit(0);
	}

	if (type_of_child == 0) //Sera de los primeros en comer
	{
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is eating");
		ft_sleep(m->time_eat);
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is sleeping");
		ft_sleep(m->time_sleep);
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is thinking");
	}
	else if (type_of_child == 1) //Comera de segundo
	{
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is sleeping");
		ft_sleep(m->time_sleep);
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is eating");
		ft_sleep(m->time_eat);
		diff = ft_diff_time(m->time_start);
		ft_print_message(diff, me, "is thinking");
	}

	// diff = ft_diff_time(m->time_start);
	// ft_print_message(diff, me, "is eating");
	// ft_sleep(m->time_eat);
	// // while (1)
	// // {
	// // 	if (ft_get_time(200) == 1)
	// // 		break;
	// // }
	// diff = ft_diff_time(m->time_start);
	// ft_print_message(diff, me, "is sleeping");
	// ft_sleep(m->time_sleep);
	// //printf("VALUE == (%i)\n", m->time_sleep);
	// // while (1)
	// // {
	// // 	if (ft_get_time(200) == 1)
	// // 		break;
	// // }
	// //diff = ft_diff_time(m->time_start);
	// diff = ft_diff_time(m->time_start);
	// ft_print_message(diff, me, "is thinking");

	// printf("START CHILD == (%i)\n", m->start);


	//m->time_start = 1;
	// usleep(5000000);
	return NULL;
}