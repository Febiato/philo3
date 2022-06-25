#include "philo.h"

long long make_time()
{
	struct timeval t;
	long long time;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (time);
}
