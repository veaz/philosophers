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

// void *ft_child(void *info)
// {
// 	t_child *struct_child;
// 	struct_child = (t_child *)info;
// 	printf("FT_CHILD #%i \n", struct_child->num_child);

// 	printf("CHILD->PHILO == (%i)\n", struct_child->num_child);

// 	printf("m->start == (%i) CHILD #%i\n", *struct_child->start, struct_child->num_child);
// 	while (1)
// 	{
// 		if (*struct_child->start == 1) // Espero a que se creen todos e inicio
// 		{
// 			//ft_sleep(10);
// 			printf("STATUS CAMBIADO #%i\n", struct_child->num_child);
// 			break;
// 		}
// 		//printf("m->start == (%i) %i\n", *struct_child->start, struct_child->num_child);
// 	}
// 	return (NULL);
// }

void *ft_child(void *info)
{
	// t_master	*master;
	// master = (t_master *)info;

	// printf("FT_CHILD == %p\n", &master);
	// printf("CHILD = number_philo %i\n", master->number_philo);
	t_master *m;
	int me;

	m = (t_master *)info;
	//printf("H: SOY EL HIJO #(%i) CREADO\n", m->childs);
	me = m->number_philo;
	printf("ME == #%i\n", me);
	//ft_print_message("SOY UN HIJO");
	// printf("h-TIME == (%i)\n", m->time_start);

	return (NULL);
}