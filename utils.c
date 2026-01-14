#include "philo.h"

void	for_free(t_arg *arg, int i)
{
	int	j;

	j = 0;
	pthread_mutex_destroy(&arg->p_lock);
	pthread_mutex_destroy(&arg->dpn_lock);
	if (i == 1)
	{
		while (j < arg->num_of_philo)
			pthread_mutex_destroy(&arg->fork[i++]);
		free(arg);
	}
}

int	for_fork(t_arg *arg)
{
	int	num;
	int	i;

	num = arg->num_of_philo;
	arg->fork = malloc(num * sizeof(pthread_mutex_t));
	if (!arg->fork)
	{
		for_free(arg, 0);
		return (1);
	}
	i = 0;
	while (i < num)
		pthread_mutex_init(&arg->fork[i++], NULL);
	return (0);
}

long long	for_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

void	print(t_arg *a, int id, char *m)
{
	pthread_mutex_lock(&a->p_lock);
	pthread_mutex_lock(&a->dpn_lock);
	if (a->dead_philo_num == 0)
		printf("%lld %d %s\n", for_time() - a->start_time, id, m);
	pthread_mutex_unlock(&a->dpn_lock);
	pthread_mutex_unlock(&a->p_lock);
}

int	is_dead(t_arg *arg)
{
	int	dead;

	pthread_mutex_lock(&arg->dpn_lock);
	dead = arg->dead_philo_num;
	pthread_mutex_unlock(&arg->dpn_lock);
	return (dead);
}
