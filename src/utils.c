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

#include "../inc/philo.h"

void	ft_end_eats(t_master *master)
{
	int	x;

	x = 0;
	pthread_mutex_lock(master->mutex_print);
	while (x < master->number_philo)
	{
		pthread_mutex_lock(master->mutex[x]);
		x++;
	}
	ft_free(master);
}

void	ft_dead(t_master *master, int x)
{
	int	diff;

	diff = ft_diff_time(master->time_start);
	ft_print_message(diff, x, "died", master->mutex_print);
	ft_free(master);
}

void	ft_free(t_master *master)
{
	int	x;

	x = 0;
	while (x < master->number_philo)
	{	
		if (master->struct_childs[x])
			free(master->struct_childs[x]);
		if (master->mutex[x])
			free(master->mutex[x]);
		x++;
	}
	if (master->struct_childs)
		free(master->struct_childs);
	if (master->mutex)
		free(master->mutex);
	if (master->mutex_print)
		free(master->mutex_print);
	if (master->childs)
		free(master->childs);
	exit(0);
}
