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

#include "../inc/philo.h"

int	ft_check_argv(char **argv)
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

int	ft_check_input(char *str)
{
	int	x;

	x = 0;
	if (str[x] == '-')
		return (1);
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
