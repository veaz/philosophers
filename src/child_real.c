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

	node = (t_child *)malloc(sizeof(t_child));
	if (!node)
		ft_free(master);
	node->num_child = philo;
	if ((philo + 1) % 2 != 0)
		node->type_of_child = 1;
	else
		node->type_of_child = 0;
	node->total_philo = master->number_philo;
	node->is_alive = 1;
	node->master = master;
	node->my_fork = master->mutex[philo];
	node->will_eat = master->will_eat;
	node->last_eat = ft_actual_time();
	node->my_eats = 0;
	if (master->number_philo == 1)
		node->other_fork = master->mutex[philo];
	else if (philo == master->number_philo - 1)
		node->other_fork = master->mutex[0];
	else
		node->other_fork = master->mutex[philo + 1];
	return (node);
}

void	ft_create_forks(t_master *master)
{
	int	x;

	x = 0;
	master->mutex = (pthread_mutex_t **)malloc
		(master->number_philo * sizeof(pthread_mutex_t *));
	if (!master->mutex)
		ft_free(master);
	while (x < master->number_philo)
	{
		master->mutex[x] = malloc(sizeof(pthread_mutex_t));
		if (!master->mutex[x])
			ft_free(master);
		pthread_mutex_init(master->mutex[x], NULL);
		x++;
	}
	master->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!master->mutex_print)
		ft_free(master);
	pthread_mutex_init(master->mutex_print, NULL);
}

void	ft_create_struct_childs(t_master *master)
{
	int	x;

	x = 0;
	master->struct_childs = malloc(master->number_philo * sizeof(t_child));
	if (!master->struct_childs)
		ft_free(master);
	while (x < master->number_philo)
	{	
		master->struct_childs[x] = ft_create_node_struct_child(x, master);
		x++;
	}
}

void	ft_create_childs(t_master *master)
{
	int				x;
	int				y;

	ft_create_forks(master);
	ft_create_struct_childs(master);
	ft_create_threads(master);
	master->start = 1;
	ft_sleep(1);
	master->time_start = ft_actual_time();
	y = 0;
	x = 0;
	while (1)
	{
		if (y == master->number_philo)
			y = 0;
		if (master->total_eats == (master->number_philo * master->will_eat))
			ft_end_eats(master);
		if (((ft_actual_time() - master->struct_childs[y]->last_eat)
				/ 1000) > master->time_dead)
			ft_dead(master, y);
		y++;
	}
}
