#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;

	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (sign * result);
}

void error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void arg_check(int ac, char **av)
{
    int i;
    int j;
    long val;

    i = 1;
    if (ac != 5 && ac != 6)
        error();
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                error();
            j++;
        }
        if (j > 10)
            error();
        val = ft_atoi(av[i]);
        if (val > 2147483647 || val <= 0)
            error();
        i++;
    }
}

long long for_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
        return (0);
    return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

void print(t_arg *a, int id, char *m)
{
    pthread_mutex_lock(&a->print_w);
    pthread_mutex_lock(&a->dpn_lock);
    if (a->dead_philo_num == 0)
        printf("%lld %d %s\n", for_time() - a->start_time, id, m);
    pthread_mutex_unlock(&a->dpn_lock);
    pthread_mutex_unlock(&a->print_w);
}
