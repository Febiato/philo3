#include "philo.h"

static int init_data(t_data *data)
{
	data->philo_number = -1;
	data->t_die = -1;
	data->t_eat = -1;
	data->t_sleep = -1;
	data->num_of_eat = -1;
	data->start_time = make_time();
	data->thr = NULL;
    data->philo = NULL;
    data->forks = NULL;
	pthread_mutex_init(&data->check, NULL);
	return (0);
}

static int data_to_struct(int argc, char **argv, t_data *data)
{
	data->philo_number = (int)ft_atoi(argv[1], data);
	data->t_die = (int)ft_atoi(argv[2], data);
	data->t_eat = (int)ft_atoi(argv[3], data);
	data->t_sleep = (int)ft_atoi(argv[4], data);
	if (argc == 6)
		data->num_of_eat = (int)ft_atoi(argv[5], data);
	if (data->philo_number == -2 || data->t_die == -2 
			|| data->t_eat== -2 || data->t_sleep == -2 
			|| data->num_of_eat == -2 || data->philo_number == 0
			|| data->num_of_eat == 0)
		return (ft_error_exit("Wrong arguments\n", data));
    data->philo = malloc(sizeof(t_philo) * data->philo_number);
	if (data->philo == NULL)
		return (-1);
    data->thr = malloc(sizeof(t_philo) * data->philo_number);
    if (data->thr == NULL)
		return (-1);
    data->forks = malloc(sizeof(t_philo) * data->philo_number);
    if (data->forks == NULL)
		return (-1);
	return (0);
}

int main (int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (argc != 5 && argc != 6)
		ft_error_exit("wrong number of arguments\n", NULL);
	data = malloc(sizeof(t_data));
	if (data == NULL || init_data(data) == -1)
		return (ft_error_exit("Memory allocation error\n", data));
    free_data(data);
	return(0);
}