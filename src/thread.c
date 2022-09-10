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

void *ft_child(void *info)
{
	long long int diff;
	// t_master	*master;
	// master = (t_master *)info;

	// printf("FT_CHILD == %p\n", &master);
	// printf("CHILD = number_philo %i\n", master->number_philo);
	t_child *c;
	int me;

	c = (t_child *)info;
	//printf("H: SOY EL HIJO #(%i) CREADO\n", m->childs);
	me = c->num_child;
	//printf("ME == #%i\n", me);
	//ft_print_message("SOY UN HIJO");
	// printf("h-TIME == (%i)\n", m->time_start);
	//printf("CHILD: TEST %i\n", c->master->start);
	while (1)
	{
		if(c->master->start == 1)
		{
			//printf("TODOS HAN INICIADO\n");
			break;
		}
	}
	//printf("CHILD: TIME == (%lli)\n", c->master->time_start);
	//printf("CHILD #%i TYPE #%i\n", me, c->type_of_child);
	if (c->type_of_child == 1)
	{
		ft_sleep(1);
	}
	// if (c->master->number_philo == 1)
	// {
	// 	ft_sleep(20);
	// }
	// if (c->type_of_child == 1) //Inicia de primero los numeros pares, 0 , 2, 4 , 6 ...
	// {
		//ft_sleep(1);
		// printf("is_alive(%i) - child_dead(%i) - will_eat(%i) - time(%i)\n", c->is_alive, c->master->child_dead, c->will_eat, ((ft_actual_time() - c->last_eat) / 1000) <= c->master->time_dead);
		// printf("CHILD:: TEST (%i), OTHER TEST(%i)\n", ((ft_actual_time() - c->last_eat) / 1000) <= c->master->time_dead, c->master->time_dead);
		// int test = ((ft_actual_time() - c->last_eat) / 1000);
		// printf("TESTTTTT == (%i)\n", test);
		// if(((ft_actual_time() - c->last_eat) / 1000) <= c->master->time_dead)
		// 	printf("SE CUMPLE\n");
		// else
		// 	printf("NO SE CUMPLE\n");
		//long long int value;

		//value = 0;
		// if (c->master->number_philo == 1)
		// {
		// 	//printf("CHILD:: SOY 1 TENGO QUE MORIR\n");
		// 	ft_print_message(ft_diff_time(c->master->time_start), me, "has taken a fork - type 1");
		// 	pthread_mutex_lock(c->my_fork);
		// 	pthread_mutex_lock(c->other_fork);
		// 	return (NULL);
		// }

		c->last_eat = ft_actual_time();
		while (c->is_alive == 1 && c->master->child_dead == 0 && c->will_eat != 0) //Si continuo vivo y no ha muerto ningun hijo
		{

			pthread_mutex_lock(c->my_fork);
			ft_print_message(ft_diff_time(c->master->time_start), me, "has taken a fork - type 1");
			pthread_mutex_lock(c->other_fork);
			ft_print_message(ft_diff_time(c->master->time_start), me, "has taken a fork - type 1");
			diff = ft_diff_time(c->master->time_start);
			ft_print_message(diff, me, "is eating - type 1");

			c->last_eat = ft_actual_time();
			ft_sleep(c->master->time_eat);
			c->will_eat = c->will_eat - 1; //NO COMERE MAS
			c->my_eats = c->my_eats + 1;
			c->master->total_eats = c->master->total_eats + 1; //SUMA TOTAL DE COMIDAS
			pthread_mutex_unlock(c->my_fork);
			pthread_mutex_unlock(c->other_fork);
			// if (c->will_eat == 0)
			// {
			// 	c->master->was_eat = c->master->was_eat + 1;
			// 	return (NULL);
			// 	//break;
			// }

			diff = ft_diff_time(c->master->time_start);
			ft_print_message(diff, me, "is sleeping - type 1");
			ft_sleep(c->master->time_sleep);


			diff = ft_diff_time(c->master->time_start);
			ft_print_message(diff, me, "is thinking - type 1 END");

		}

	return (NULL);
}