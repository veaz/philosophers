/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:04:07 by vaguilar          #+#    #+#             */
/*   Updated: 2022/06/25 17:12:07 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_argv(char **argv) //Verifico los primeros argumentos que recibo
{
	int	x;

	x = 1;
	while (argv[x] != NULL)
	{
		if (ft_check_input(argv[x]) == 1)
			return (1);
		x++;
	}
	return (0);
}

int	ft_check_input(char *str) //Verifico que sea numero y que no sea mayor a los maximos y minimos
{
	int	sig;
	int	x;

	x = 0;
	sig = 0;
	if (str[x] == '-' || str[x] == '+')
	{
		sig = 1;
		x++;
	}
	while (str[x] != '\0')
	{
		if (str[x] <= 47 || str[x] >= 58)
			return (1);
		x++;
	}
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		return (1);
	return (0);
}