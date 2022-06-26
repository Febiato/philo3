/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:09 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 18:43:55 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_eat_check(t_data *data)
{
	int	i;
	int	summ_eat;

	i = 0;
	summ_eat = 0;
	while (i < data->philo_number)
	{
		pthread_mutex_lock(&data->check);
		if (data->philo[i].eat_count >= data->num_of_eat)
			summ_eat++;
		pthread_mutex_unlock(&data->check);
		i++;
	}
	if (summ_eat == data->philo_number)
	{
		pthread_mutex_lock(&data->check);
		return (-1);
	}
	return (0);
}

static int	ft_death_check(t_data *data)
{
	int			i;
	long long	time;

	i = 0;
	time = make_time();
	while (i < data->philo_number)
	{
		pthread_mutex_lock(&data->check);
		if (time - data->start_time - data->philo[i].last_eating > data->t_die)
		{
			printf("%lld %d died\n",
				time - data->start_time, data->philo[i].number);
			return (-1);
		}
		pthread_mutex_unlock(&data->check);
		i++;
	}
	return (0);
}

int	ft_check(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < data->philo_number)
		{
			if (ft_death_check(data) == -1)
				return (-1);
			if (data->num_of_eat != -1)
			{
				if (ft_eat_check(data) == -1)
					return (-1);
			}
			i++;
		}
		i = 0;
		usleep(500);
	}
}
