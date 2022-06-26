/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:30 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 18:45:38 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fork_to_philo(t_philo *philo)
{
	if (philo->number == philo->philo_data->philo_number)
	{
		pthread_mutex_lock(philo->right);
		print_str(philo, philo->number, " has taken a fork");
		pthread_mutex_lock(philo->left);
		print_str(philo, philo->number, " has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left);
		print_str(philo, philo->number, " has taken a fork");
		pthread_mutex_lock(philo->right);
		print_str(philo, philo->number, " has taken a fork");
	}
}

static void	*philo_to_life(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if (philo->number % 2 == 0)
		usleep(500);
	while (1)
	{
		fork_to_philo(philo);
		print_str(philo, philo->number, " is eating");
		pthread_mutex_lock(&philo->philo_data->check);
		philo->last_eating = make_time() - philo->philo_data->start_time;
		pthread_mutex_unlock(&philo->philo_data->check);
		ft_sleep(philo->philo_data->t_eat, make_time());
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_lock(&philo->philo_data->check);
		if (philo->philo_data->num_of_eat != -1)
			philo->eat_count++;
		pthread_mutex_unlock(&philo->philo_data->check);
		print_str(philo, philo->number, " is sleeping");
		ft_sleep(philo->philo_data->t_sleep, make_time());
		print_str(philo, philo->number, " is thinking");
		usleep(100);
	}
	return (0);
}

int	ft_make_threads(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = make_time();
	while (i < data->philo_number)
	{
		data->philo[i].last_eating = make_time() - data->start_time;
		pthread_create(&data->thr[data->philo_number], NULL,
			philo_to_life, (void *)&data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->philo_number)
	{
		pthread_detach(data->thr[data->philo->number - 1]);
		i++;
	}
	return (0);
}
