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

void	ft_first_value(t_master *master, char **argv) //Primer valor a la estructura, caso normal y especial
{
	master->number_philo = ft_atoi(argv[1]);
	master->time_dead = ft_atoi(argv[2]);
	master->time_eat = ft_atoi(argv[3]);
	master->time_sleep = ft_atoi(argv[4]);
	master->start = 0;
	master->child_dead = 0;
	master->total_eats = 0;
	if (master->argc == 5)
		master->will_eat = ft_atoi(argv[5]);
	else
		master->will_eat = -1;
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
		if (ft_check_argv(argv) == 1) //Verificacion de errores
		{
			printf("ERROR CON UN ARGUMENTO\n");
			return (0);
		}
	}
	ft_first_value(&master, argv); // Le doy valor a la estructura

	if (argc == 4) //Innecesario, pendiente de eliminar
	{
		printf("CASO NORMAL\n");
	}
	else if (master.argc == 5)
	{
		printf("CASO PECULIAR\n");
	}
	ft_create_childs(&master); // Inicio el programa
	return (0);
}

/* 

FALTA

caso de 1
matar desde el main

caso de 200 800 200 200






*/