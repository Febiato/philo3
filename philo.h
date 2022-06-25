#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_philo t_philo;
typedef struct s_data t_data;

struct s_data {
	int			philo_number;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			num_of_eat;
	long long	start_time;
	t_mutex		check;
	t_philo		*philo;
	t_mutex		*forks;
	pthread_t	*thr;
};

struct s_philo {
	int			number;
	int			eat_count;
	long long	last_eating;
	t_data		*philo_data;
	t_mutex		*left;
	t_mutex		*right;
};

/* error_exit */
void free_data(t_data *data);
int ft_error_exit(char *str, t_data *data);

/* utils */
long long make_time();

#endif