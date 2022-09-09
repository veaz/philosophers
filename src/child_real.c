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



// void	ft_first_value_struct_child(t_master *master) //NO USADA
// {
// 	int	x;

// 	x = 0;
// 	printf("NUMBER_PHILO == (%i)\n", master->number_philo);
// 	master->thread_child = (t_child **)malloc(master->number_philo * sizeof(t_child *));

// 	while (x < master->number_philo)
// 	{
// 		master->thread_child[x] = ft_create_data(x,master);
// 		x++;
// 	}

// 	//printf("QUE TAN FUNCIONAL\n");
// 	//exit(0);
//}



t_child	*ft_create_node_struct_child(int philo, t_master *master)
{
	t_child	*node;

	printf("ft_create_node_struct_child #%i\n",philo);
	node = (t_child *)malloc(sizeof(t_child));

	node->num_child = philo;
	node->time_dead =  master->time_dead;
	node->time_eat = master->time_eat;
	node->time_sleep = master->time_sleep;
	node->will_eat = master->will_eat;
	node->time_start = &master->time_start;
	node->start = &master->start;
	node->my_fork = master->mutex[philo];
	if (master->number_philo == 1)//Si solo hay un filosofo
	{
		node->other_fork = master->mutex[philo];
	}
	else if (philo == master->number_philo)//Si estoy en el ultimo filosofo
	{
		node->other_fork = master->mutex[0];
	}
	else
	{
		node->other_fork = master->mutex[philo + 1];
	}
	node->next = NULL;
	return (node);
}

void	ft_create_childs(t_master *master) //Sex function
{
	t_child	*temp;
	t_child	*aux;
    int x;

    x = 0;
    printf("FT_CREATE_CHILDS REAL\n");

    /*	CREACION DE TENEDORES	*/
	master->mutex = (pthread_mutex_t **)malloc(master->number_philo * sizeof(pthread_mutex_t *));
	while (x < master->number_philo)
	{
		
		master->mutex[x] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(master->mutex[x], NULL);
		x++;
	}
    printf("TENEDORES CREADOS\n");
	/* FIN DE CREACION DE TENEDORES*/



    /*  CREACION DE ESTRUCTURA DE HIJOS */
    x = 0;
    master->struct_child = ft_create_node_struct_child(x , master);
	x++;
	aux = master->struct_child;
    while (x < master->number_philo)
	{
		temp = ft_create_node_struct_child(x , master);
		aux->next = temp;
		aux = aux->next;
		x++;
	}
	//printf("PHILO == (%i), PHILO 2 == (%i)\n", master->struct_child->num_child, master->struct_child->next->num_child);
	//printf("PHILO 3 == (%i)\n", master->struct_child->num_child);
	// printf("\n\nVERIFICACION DE VALORES\n");
	// printf("MASTER->START == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->start);
	// master->start = 42;
	// printf("MASTER->START == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->start);
	// printf("MASTER->START2 == (%i) || N1->START == (%i)\n", master->start, *master->struct_child->next->start);
	// exit(0);
    /*  FIN DE CREACION DE ESCTRUCTURA DE HIJOS */



    /*  CREACION DE HIJOS   */
	x = 0;
	master->childs = (pthread_t *)malloc(master->number_philo * sizeof(pthread_t *)); // WARNING : ES NECESARIO AGREGAR +1 ??

	t_child *test;
	test = master->struct_child;
	//printf("TEST PHILO == (%i), PHILO 2 == (%i)\n", test->num_child, test->next->num_child);
	printf("MAIN POINTER MASTER %p\n", &master);
	printf("MAIN = number_philo %i\n", master->number_philo);
	while (x < master->number_philo) //Creo la cantidad de hijos necesarios, enviandole de momento la estructura master
	{
		//if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)&master->struct_child[x]) == 0)
		//if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)&test) == 0)
		if (pthread_create(&master->childs[x] , NULL , ft_child, (void *)&master) == 0)
			x++;
		else
			printf("UPS! ERROR HAVING SEX, PLEASE DONT USE CONDON, WE NEED CHILDS\n");
		test = test->next;
		
	}
	printf("HIJOS CREADOS == (%i)\n", x);
    /*  FIN DE CREACION DE HIJOS    */

	master->start = 1;
	x = 0;
	printf("ESPERANDO A QUE MUERAN\n");
	while (1)
	{
		if (pthread_join(master->childs[x], NULL) == 0)
			x++;
		if (x == master->number_philo)
		{
			printf("TODOS TERMINARON\n");
			break;
		}
	}
	printf("\nESPERA PERFECTA\n");

}