#include "philo.h"

void free_data(t_data *data)
{
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
	free(data);
	data = NULL;
}

int ft_error_exit(char *str, t_data *data)
{
	if (data != NULL)
		free_data(data);
	if (str != NULL)
		printf("%s", str);
	return (-1);
}