/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:26 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 21:06:53 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_data *data)
{
	data->philo_number = -1;
	data->t_die = -1;
	data->t_eat = -1;
	data->t_sleep = -1;
	data->num_of_eat = -1;
	data->start_time = 0;
	data->thr = NULL;
	data->philo = NULL;
	data->forks = NULL;
	pthread_mutex_init(&data->check, NULL);
	return (0);
}

static int	data_to_struct(int argc, char **argv, t_data *data)
{
	data->philo_number = (int)ft_atoi(argv[1], 0);
	data->t_die = (int)ft_atoi(argv[2], 0);
	data->t_eat = (int)ft_atoi(argv[3], 0);
	data->t_sleep = (int)ft_atoi(argv[4], 0);
	if (argc == 6)
		data->num_of_eat = (int)ft_atoi(argv[5], 0);
	if (data->philo_number == -2 || data->t_die == -2 || data->t_eat == -2
		|| data->t_sleep == -2 || data->num_of_eat == -2
		|| data->philo_number == 0 || data->num_of_eat == 0)
		return (ft_error_exit("Wrong arguments\n", data));
	data->philo = malloc(sizeof(t_philo) * data->philo_number);
	if (data->philo == NULL)
		return (ft_error_exit("Memory allocation error\n", data));
	data->thr = malloc(sizeof(t_philo) * data->philo_number);
	if (data->thr == NULL)
		return (ft_error_exit("Memory allocation error\n", data));
	data->forks = malloc(sizeof(t_philo) * data->philo_number);
	if (data->forks == NULL)
		return (ft_error_exit("Memory allocation error\n", data));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc != 5 && argc != 6)
		return (ft_error_exit("wrong number of arguments\n", NULL));
	data = malloc(sizeof(t_data));
	if (data == NULL || init_data(data) == -1)
		return (ft_error_exit("Memory allocation error\n", data));
	if (data_to_struct(argc, argv, data) == -1)
		return (-1);
	philo_init(data, data->philo);
	ft_make_threads(data);
	ft_check(data);
	free_data(data);
	return (0);
}
