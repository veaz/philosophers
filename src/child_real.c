/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/07/21 14:43:16 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_child	*ft_create_node_struct_child(int philo, t_master *master)
{
	t_child	*node;

	//printf("ft_create_node_struct_child #%i\n",philo);
	node = (t_child *)malloc(sizeof(t_child));

	node->num_child = philo;
	//printf("NODE NUM CHILD == (%i)\n", node.num_child);
	printf("PHILO %i - NUMBER_PHILO %i\n", philo, master->number_philo);
	if ((philo + 1) % 2 != 0)
	{
		node->type_of_child = 1;
	}
	else
		node->type_of_child = 0;
	node->total_philo = master->number_philo;
	node->is_alive = 1;
	node->master = master;
	node->my_fork = master->mutex[philo];
	node->will_eat = master->will_eat;
	node->last_eat = ft_actual_time();
	node->my_eats = 0;
	if (master->number_philo == 1)//Si solo hay un filosofo
	{
		node->other_fork = master->mutex[philo];
	}
	else if (philo == master->number_philo - 1)//Si estoy en el ultimo filosofo
	{
		printf("\n\nELSE IF\n\n");
		node->other_fork = master->mutex[0];
	}
	else
	{
		node->other_fork = master->mutex[philo + 1];
	}
	//printf("ASIGNADO MUTEX %p\n", node)
	return (node);
}

void	ft_create_childs(t_master *master) //Sex function //INICIO DEL PROGRAMA
{
	t_child	**struct_childs;
	//t_child	aux;
    int x;

    x = 0;
//	struct_childs = NULL;
    printf("FT_CREATE_CHILDS REAL\n");

    /*	CREACION DE TENEDORES	*/
	master->mutex = (pthread_mutex_t **)malloc(master->number_philo * sizeof(pthread_mutex_t *));
	while (x < master->number_philo)
	{
		
		master->mutex[x] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(master->mutex[x], NULL);
		x++;
	}
	master->mutex_print = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(master->mutex_print, NULL);
    printf("TENEDORES CREADOS\n\n");
	/* FIN DE CREACION DE TENEDORES*/


    /*  CREACION DE ESTRUCTURA DE HIJOS */
    x = 0;
    // master->struct_child = ft_create_node_struct_child(x , master);
	// x++;
	// aux = master->struct_child;
	struct_childs = malloc(master->number_philo * sizeof(struct_childs));
	//struct_childs = NULL;
    while (x < master->number_philo)
	{

	//	struct_childs[x] = (t_child *)malloc(sizeof(struct_childs));	
		struct_childs[x] = ft_create_node_struct_child(x, master);
		//printf("X == (%i)\n", x);
		//printf("STRUCT_CHILDS[%i] == (%i)\n", x, struct_childs[x]->num_child);
		
		x++;
	}
	//printf("PHILO == (%i), PHILO 2 == (%i)\n", master->struct_child->num_child, master->struct_child->next->num_child);
	//printf("PHILO 3 == (%i)\n", master->struct_child->num_child);
	// printf("\n\nVERIFICACION DE VALORES\n");
	// printf("MASTER->START == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->start);
	// master->start = 42;
	// printf("MASTER->START == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->start);
	// printf("MASTER->START2 == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->next->start);
    /*  FIN DE CREACION DE ESCTRUCTURA DE HIJOS */



    /*  CREACION DE HIJOS   */
	x = 0;
	master->childs = (pthread_t *)malloc(master->number_philo * sizeof(pthread_t *)); // WARNING : ES NECESARIO AGREGAR +1 ??

	//t_child *test;
	//test = master->struct_child;
	//printf("TEST PHILO == (%i), PHILO 2 == (%i)\n", test->num_child, test->next->num_child);
	//printf("MAIN POINTER MASTER %p\n", &master);
	//printf("MAIN = number_philo %i\n", master->number_philo);
	//aux = *struct_childs;
	while (x < master->number_philo) //Creo la cantidad de hijos necesarios, enviandole de momento la estructura master
	{
		//if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)&master->struct_child[x]) == 0)
		//if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)&test) == 0)
		//printf("NUMERO DE HIJO == (%i)\n", struct_childs[x]->num_child);
		if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)struct_childs[x]) == 0)
		{
			x++;
			//aux = struct_childs[x];
		}
		else
			printf("UPS! ERROR HAVING SEX, PLEASE DONT USE CONDON, WE NEED CHILDS\n");
		//test = test->next;
		
	}
	printf("HIJOS CREADOS == (%i)\n\n", x);
    // /*  FIN DE CREACION DE HIJOS    */

	master->start = 1;
	ft_sleep(1);
	master->time_start = ft_actual_time();

	if(master->number_philo == 1)
	{
		printf("MAIN: SOLO TENGO 1 PHILO\n");
		ft_sleep(100);
		printf("DETACH == (%i)\n", pthread_detach(master->childs[0]));

		printf("0 0 died\n");
		exit(0);
		// while(1)
		// {
		// 	if (master->time_start )
		// }

	}
	//printf("MAIN: TIME == (%lli)\n", master->time_start);
	int y;
	y = 0;
	x = 0;
	printf("ESPERANDO A QUE MUERAN\n");
	long long int value;
	int diff;
	//while (1)
	while (1)
	{
		// while (y < master->number_philo)
		// {
		// 	if (((ft_actual_time() - struct_childs[y]->last_eat) / 1000) > master->time_dead)
		// 	{
		// 		printf("MAIN:: ALGUIEN TIENE QUE MORIR #%i\n", y);
		// 	}
		// 	y++;
		// }
		//y = 0;
		if (master->total_eats == (master->number_philo * master->will_eat)) //Si ya todos comieron
		{
			printf("YA TODOS COMIERON OK\n");
			while (y < master->number_philo)
			{
				pthread_mutex_lock(master->mutex[y]);
				y++;
				exit(0);
			}
			printf("EXIT\n");
			break;
		}
		// while (y < master->number_philo)
		// {
			//if (struct_childs[x]->last_eat)
			if (y == master->number_philo)
			{
				y = 0;
			}
			if (master->will_eat != -1)//Si es el caso especial
			{
				if (struct_childs[y]->my_eats == master->will_eat)
				{
					diff = ft_diff_time(master->time_start);
					printf("\n\n%i KILLING #%i res(%i)\n\n", diff / 1000, y, pthread_detach(master->childs[y]));

					struct_childs[y]->my_eats = -1;
				}
			}

			value = ft_actual_time();
			if (((value - struct_childs[y]->last_eat) / 1000) > master->time_dead)
			{
				printf("VALUE(%lli) - LAST_EAT(%lli) / 1000 = (%lli) > TIME_DEAD(%lli)\n", value, struct_childs[y]->last_eat, (value - struct_childs[y]->last_eat) / 1000, master->time_dead);
				printf("EL TIEMPO PARA (%i) YA PASO MAIN, %i %i\n", x, master->total_eats, master->will_eat);
				diff = ft_diff_time(master->time_start);
				ft_print_message(diff, y, "dead\n");
				exit(0);
			}
			//printf("ok:: VALUE(%lli) - LAST_EAT(%lli) / 1000 = (%lli) > TIME_DEAD(%lli)\n", value, struct_childs[y]->last_eat, (value - struct_childs[y]->last_eat) / 1000, master->time_dead);

			y++;
			//printf("MAIN:: TIEMPOS ok \n");
		// }
		y = 0;

		// if (master->child_dead == 1)
		// {
		// 	printf("ALGUIEN HA MUERTO\n");
		// 	while (y < master->number_philo)
		// 	{
		// 		pthread_mutex_lock(master->mutex[y]);
		// 		y++;
		// 		exit(0);
		// 	}
		// }
		// if (pthread_join(master->childs[x], NULL) == 0)
		// 	x++;
		// if (x == master->number_philo)
		// {
		// 	printf("TODOS TERMINARON");
		// 	break;
		// }
	}
	printf(" ESPERA PERFECTA\n");


}