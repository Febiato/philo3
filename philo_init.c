/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:33 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 18:45:54 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	forks_init(t_philo *philo)
{
	if (philo->number != philo->philo_data->philo_number)
	{
		philo->left = &philo->philo_data->forks[philo->number - 1];
		pthread_mutex_init(philo->left, NULL);
		philo->right = &philo->philo_data->forks[philo->number];
		pthread_mutex_init(philo->right, NULL);
	}
	else
	{
		philo->left = &philo->philo_data->forks[philo->number - 1];
		pthread_mutex_init(philo->left, NULL);
		philo->right = &philo->philo_data->forks[0];
		pthread_mutex_init(philo->right, NULL);
	}
}

int	philo_init(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->philo_number)
	{
		philo[i].number = i + 1;
		philo[i].eat_count = 0;
		philo[i].philo_data = data;
		philo[i].last_eating = data->start_time;
		forks_init(&philo[i]);
		i++;
	}
	i = 0;
	return (0);
}
