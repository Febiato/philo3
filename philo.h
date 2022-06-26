/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cthresh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:33:36 by cthresh           #+#    #+#             */
/*   Updated: 2022/06/26 18:47:00 by cthresh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

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
void		free_data(t_data *data);
int			ft_error_exit(char *str, t_data *data);

/* utils */
long long	make_time(void);
long long	ft_atoi(const char *str);
void		print_str(t_philo *philo, int number, char *str);
void		ft_sleep(long long time, long long real_time);

/* philo_init */
int			philo_init(t_data *data, t_philo *philo);

/* make_threads */
int			ft_make_threads(t_data *data);

/* check */
int			ft_check(t_data *data);

#endif