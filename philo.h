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

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h> //PRINTF 
# include <sys/time.h> //FECHA
# include <unistd.h> //USLEEP
# include <pthread.h> //CREACION DE HILOS
# include <stdlib.h> //MALLOC

typedef struct s_master
{
	int	argc;
	int	number_philo;
	int	time_dead;
	int	time_eat;
	int	time_sleep;
	int	will_eat;
	int	time_start;
	int start;
	int	childs;
	pthread_mutex_t	mutex;
}t_master;

/* LIBFT */
int		ft_atoi(const char *str);
long	ft_atoi_long(const char *str);

/* CHECK */
int	ft_check_argv(char **argv);
int	ft_check_input(char *str);

/* PRINT */
void	ft_print_message(int time, int child,  char *message);

/* CHILD */
void	ft_create_childs(t_master *master);
void	*ft_child(void *master);

/* TIME */
void	ft_sleep(int	ms);
int		ft_get_time(int ms);
long long int	ft_diff_time(int time_start);

#endif