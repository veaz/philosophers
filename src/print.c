/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/07/07 16:14:42 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print_message(int time, int child,  char *message)
{
	pthread_mutex_t	mutex1;

	pthread_mutex_init(&mutex1, NULL); //Si se envia NULL se establecen los atributos de defecto
	pthread_mutex_lock(&mutex1); //Bloqueo y mas nadie puede escribir
	printf("%i %i %s\n",time / 1000, child + 1, message);
	pthread_mutex_unlock(&mutex1); //Desbloqueo y que continue el siguiente a escribir
}
