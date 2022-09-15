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

void	*ft_child(void *info)
{
	long long int	diff;
	int				me;
	t_child			*c;

	c = (t_child *)info;
	me = c->num_child;
	while (1)
	{
		if (c->master->start == 1)
		{
			ft_sleep(1);
			break ;
		}
	}
	if (c->type_of_child == 1)
	{
		ft_sleep(1);
	}
	c->last_eat = ft_actual_time();
	while (c->is_alive == 1 && c->master->child_dead == 0 && c->will_eat != 0)
	{
		pthread_mutex_lock(c->my_fork);
		ft_print_message(ft_diff_time(c->master->time_start),
			me, "has taken a fork", c->master->mutex_print);
		pthread_mutex_lock(c->other_fork);
		ft_print_message(ft_diff_time(c->master->time_start),
			me, "has taken a fork", c->master->mutex_print);
		diff = ft_diff_time(c->master->time_start);
		c->last_eat = ft_actual_time();
		ft_print_message(diff, me, "is eating", c->master->mutex_print);
		ft_sleep(c->master->time_eat);
		c->will_eat = c->will_eat - 1;
		c->my_eats = c->my_eats + 1;
		c->master->total_eats = c->master->total_eats + 1;
		pthread_mutex_unlock(c->my_fork);
		pthread_mutex_unlock(c->other_fork);
		if (c->will_eat == 0)
			return (NULL);
		diff = ft_diff_time(c->master->time_start);
		ft_print_message(diff, me, "is sleeping", c->master->mutex_print);
		ft_sleep(c->master->time_sleep);
		diff = ft_diff_time(c->master->time_start);
		ft_print_message(diff, me, "is thinking", c->master->mutex_print);
	}
	return (NULL);
}
