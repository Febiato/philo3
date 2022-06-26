/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:21 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 18:45:14 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	all_mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo != NULL)
	{
		while (i < data->philo_number)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
}

void	free_data(t_data *data)
{
	all_mutex_destroy(data);
	pthread_mutex_destroy(&data->check);
	if (data->philo != NULL)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->thr != NULL)
	{
		free(data->thr);
		data->thr = NULL;
	}
	if (data->forks != NULL)
	{
		free(data->forks);
		data->forks = NULL;
	}
	free(data);
	data = NULL;
}

int	ft_error_exit(char *str, t_data *data)
{
	if (data != NULL)
		free_data(data);
	if (str != NULL)
		printf("%s", str);
	return (-1);
}
