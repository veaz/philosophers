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

#include "../include/philo.h"

t_child	*ft_create_data(int number_philo, t_master *master)
{
	t_child	*thread_child;


	printf("FT_CREATE_DATA #%i\n",number_philo);
	thread_child = (t_child *)malloc(sizeof(t_child));

	(void)master;

	// number_philo = number_philo - 1;

	thread_child->num_child = number_philo;
	thread_child->time_dead =  master->time_dead;
	thread_child->time_eat = master->time_eat;
	thread_child->time_sleep = master->time_sleep;
	thread_child->will_eat = master->will_eat;
	thread_child->time_start = &master->time_start;
	thread_child->start = &master->start;
	

	thread_child->my_fork = master->mutex[number_philo];

	if (master->number_philo == 1)//Si solo hay un filosofo
	{
		thread_child->other_fork = master->mutex[number_philo];
	}
	else if (number_philo == master->number_philo)//Si estoy en el ultimo filosofo
	{
		thread_child->other_fork = master->mutex[0];
	}
	else
	{
		thread_child->other_fork = master->mutex[number_philo + 1];
	}

	thread_child->next = NULL;


	return (thread_child);
}



void	ft_first_value_struct_child(t_master *master)
{
	int	x;

	x = 0;
	printf("NUMBER_PHILO == (%i)\n", master->number_philo);
	master->thread_child = (t_child **)malloc(master->number_philo * sizeof(t_child *));

	while (x < master->number_philo)
	{
		master->thread_child[x] = ft_create_data(x,master);
		x++;
	}

	//printf("QUE TAN FUNCIONAL\n");
	//exit(0);


}



void	ft_create_childs_222(t_master *master) //Sex function
{
	struct timeval time;
	pthread_t *childs;
	int	seconds;
	int	microseconds;

	//pthread_mutex_t	**tenedores;
	//pthread_mutex_t	*aux;

	// pthread_t h1[4];

	// t_master test;
	// test = *master; // SE CASTEA SOLO PARA ENVIAR A LOS HIJOS
	t_child **test;
	
	
	int	x;

	x = 0;
	printf("FT_CREATE_CHILDS\n");



	/*	CREACION DE TENEDORES	*/
	childs = (pthread_t *)malloc(master->number_philo * sizeof(pthread_t *)); // WARNING : ES NECESARIO AGREGAR +1 ??

	master->mutex = (pthread_mutex_t **)malloc(master->number_philo * sizeof(pthread_mutex_t *));

	//tenedores = (pthread_mutex_t **)malloc(master->number_philo * sizeof(pthread_mutex_t *));
	while (x < master->number_philo)
	{
		
		master->mutex[x] = malloc(sizeof(pthread_mutex_t));
		//aux = *master->mutex[x];
		//aux = tenedores[x];
		pthread_mutex_init(master->mutex[x], NULL);
		x++;
	}
	/* FIN DE CREACION DE TENEDORES*/

	ft_first_value_childs(master);



	//exit(0);


	// printf("h-TIME MAIN == (%i)\n", master->time_start);

	x = 0;

	printf("HIJOS Y TENEDORES CREADOS CORRECTAMENTE\n");

	/*	HIJOS Y TENEDORES CREADOS EN ESTRUCTURA MASTER	*/

	


	// (void)test;
	test = master->thread_child;
	//test.childs = 0;
	while (x < master->number_philo) //Creo la cantidad de hijos necesarios, enviandole de momento la estructura master
	{
		if (pthread_create(&childs[x] , NULL , ft_child, (void *)test[x]) == 0)
			x++;
		else
			printf("UPS! ERROR HAVING SEX, PLEASE DONT USE CONDON, WE NEED CHILDS\n");
	//	test.childs++;
	}
	printf("HIJOS CREADOS == (%i)\n", x);
	

	if (gettimeofday(&time, NULL) == 0) //Significa que se realizo de manera correcta
	{
		master->time_start = time.tv_sec; //tv_sec --> Segundos && tv_usec --> Microsegundos
		seconds = time.tv_sec;
		microseconds = time.tv_usec;
		master->time_start = (time.tv_sec * 1000000) + time.tv_usec;
		//printf("TIEMPO DE INICIO EN SEGUNDOS == (%li), + USEC == (%i)\n", time.tv_sec, test.time_start);
		// printf("ANYOS == (%i), DIAS == (%i), HORAS == (%i), MINUTOS == (%i)\n", (((seconds / 60) / 60 ) / 24) / 365 , ((seconds / 60) / 60 ) / 24 ,  (seconds / 60) / 60, seconds / 60);
		// printf("SECONDS == (%i), MICROSECONDS == (%i)\n", seconds, microseconds);
	}
	else
		printf("ERROR AL MOMENTO DE OBTENER EL TIEMPO\n");

	printf("TIEMPO OBTENIDO\n");
	//usleep(2000);

	//ft_sleep(100);
	master->thread_child[0]->start = &master->start;
	printf("PRE START CHILD == (%p)\n", master->thread_child[0]->start);
	printf("PRE START CHILD START == (%p)\n", &master->start);
	master->start = 1; // INICIO TODOS LOS HIJOS
	printf("START CHILD == (%i)\n", *master->thread_child[0]->start);
	//exit(0);
	//printf("START NOW == (%i)\n", test.start);
	// usleep(5000);
	x = 0;
	while (1)
	{
		if (pthread_join(childs[x], NULL) == 0)
			x++;
		if (x == master->number_philo)
		{
			printf("TODOS TERMINARON\n");
			break;
		}
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
	//t_master *m;
	t_child *m;
	long long int diff;
	int me;
	int	type_of_child;
	//pthread_mutex_t	mutex;

	//m = (t_master *)master;
	m = (t_child *)master;
	//printf("H: SOY EL HIJO #(%i) CREADO\n", m->childs);
	me = m->childs;
	type_of_child = 0;
	//ft_print_message("SOY UN HIJO");
	// printf("h-TIME == (%i)\n", m->time_start);
	printf("PRE m->start == (%i)\n", *m->start);
	while (1)
	{
		if (*m->start == 1) // Espero a que se creen todos e inicio
		{
			//ft_sleep(10);
			break;
		}
		printf("m->start == (%i)\n", *m->start);
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
		//printf("SOY #(%i) Y SOY TIPO 1\n", me + 1);
		type_of_child = 1;
	}
	// else
	// 	printf("SOY #(%i) Y NO ME INTERESA MAS\n", me + 1);

	// if (pthread_mutex_lock(m->mutex[me]) == 0)
	// {
	// 	printf("CHILD BLOCK GOOD BYE\n");
	// 	return NULL;
	// 	//exit(0);
	// }
	long long int eat;
	long long int test;
	int	x;
	test = 0;
	eat = 0;
	x = 0;
	printf("ME == (%d)\n", me);
	if (type_of_child == 0) //Sera de los primeros en comer
	{
		eat = ft_actual_time() / 1000;
		//printf("EAT == (%lld)\n", eat);

		while (test <= m->time_dead && x < m->will_eat) //Si ha transcorrudien el tiempo de morir, o ha comido x cantidad de veces
		{
			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is eating");

			//printf("INTENTANDO BLOQUEAR MUTEX (%d) , & (%p)\n", me, m->mutex[me - 1]);
			// mutex = *(m->mutex[me - 1]);
			// pthread_mutex_lock(&mutex); //Bloqueo para comer
			printf("BLOQUEADO (%d)\n", me - 1);
			
			eat = ft_actual_time();
			x++;
			//printf("EAT == (%lld)\nEAT / 1000 == (%lld)\n", eat, eat / 1000);
			eat = eat / 1000;
			ft_sleep(m->time_eat);
			// pthread_mutex_unlock(m->mutex[me - 1]);
			//exit(0);

			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is sleeping");
			ft_sleep(m->time_sleep);
			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is thinking");
			test = (ft_actual_time() / 1000) - eat;
			printf("TEST == 0(%lld)\n", test);
			//printf("WHILE == (%lld)\n", (ft_actual_time() / 1000) - eat);
			//exit(0);
		}
		//printf("WHILE OUT== (%lld), (%lld)\n", (ft_actual_time() / 1000) - eat, eat);
		printf("HA MUERDO 0(%d), COMI == (%d)\n", me, x);
		ft_sleep(m->time_sleep);
		//exit(0);
		return (NULL);
	}
	else if (type_of_child == 1) //Comera de segundo
	{
		//eat = ft_actual_time() / 1000;
		//printf("EAT == (%lld)\n", eat);
		while (test <= m->time_dead && x < m->will_eat)
		{
			//printf("SOY (%d), COMERE DE SEGUNDO\n", me);
			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is sleeping");
			ft_sleep(m->time_sleep);
			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is eating");
			eat = ft_actual_time();
			eat = eat / 1000;
			x++;
			ft_sleep(m->time_eat);
			diff = ft_diff_time(*m->time_start);
			ft_print_message(diff, me, "is thinking");
			test = (ft_actual_time() / 1000) - eat;
			printf("TEST 1== (%lld)\n", test);
		}
		printf("HA MUERDO 1(%d), COMI == (%d)\n", me, x);
		ft_sleep(m->time_sleep);
		//exit(0);
		return (NULL);
	}
	printf("ALMOST OUT\n");
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
	return (NULL);
}
