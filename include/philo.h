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
	long long int	time_dead;
	int	time_eat;
	int	time_sleep;
	int	will_eat;
	long long int	time_start;
	int				child_dead; //verifico si algun hijo ha muerto
	int start;
	int	number_childs;
	int				total_eats;
	pthread_mutex_t	**mutex;
	pthread_mutex_t	*mutex_print;
	pthread_t *childs; //Listado de hilos/hijos
}t_master;

typedef struct s_child 
{
	pthread_mutex_t	*my_fork;
	pthread_mutex_t	*other_fork;
	int				num_child;
	int				type_of_child;
	int				total_philo;
	int				is_alive;
	int				will_eat;
	int				my_eats;
	long long int	last_eat;
	t_master *master;
}	t_child;

/* LIBFT */
int		ft_atoi(const char *str);
long	ft_atoi_long(const char *str);

/* CHECK */
int	ft_check_argv(char **argv);
int	ft_check_input(char *str);

/* PRINT */
void	ft_print_message(int time, int child,  char *message, pthread_mutex_t *mutex_print);

/* CHILD */
 void	ft_create_childs(t_master *master);
// void	*ft_child(void *master);

/*	THREAD	*/
void *ft_child(void *info);

/* TIME */
void	ft_sleep(long long int	ms);
int		ft_get_time(int ms);
long long int	ft_actual_time();
long long int	ft_diff_time(int time_start);

#endif