/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:39 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 19:20:20 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_str(t_philo *philo, int number, char *str)
{
	pthread_mutex_lock(&philo->philo_data->check);
	printf("%lld %d%s\n",
		make_time() - philo->philo_data->start_time, number, str);
	pthread_mutex_unlock(&philo->philo_data->check);
}

long long	make_time(void)
{
	struct timeval	t;
	long long		time;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}

long long	ft_atoi(const char *str)
{
	long long	result;
	long long	i;
	long long	plus;

	plus = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			return (-2);
		i++;
	}
	if (str[i] == '\0' || (str[i] < '0' || str[i] > '9'))
		return (-2);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result * plus > 2147483647 || result * plus < -2147483648)
			return (-2);
		i++;
	}
	return (result * plus);
}

void	ft_sleep(long long time, long long real_time)
{
	while (time > (make_time() - real_time))
		usleep(10);
}
