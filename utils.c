#include "philo.h"

void for_fork(t_arg *arg)
{
    int num;
    int i;

    num = arg->num_of_philo;
    arg->fork = malloc(num * sizeof(pthread_mutex_t));
    if (!arg->fork)
        error();
    i = 0;
    while (i < num)
        pthread_mutex_init(&arg->fork[i++], NULL);
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

int one_philo(t_philo *p)
{
    if (p->arg->num_of_philo == 1)
    {
        p->last_eat = for_time();
        pthread_mutex_lock(&p->arg->fork[p->r_fork]);
        print(p->arg, p->l_fork + 1, "has taken a fork");
        while (!p->arg->dead_philo_num)
            usleep(100);
        pthread_mutex_unlock(&p->arg->fork[p->r_fork]);
        return (1);
    }
    return (0);
}

int is_dead(t_arg *arg)
{
    int dead;

    pthread_mutex_lock(&arg->dpn_lock);
    dead = arg->dead_philo_num;
    pthread_mutex_unlock(&arg->dpn_lock);
    return (dead);
}

int is_over(t_arg *arg)
{
    int over;

    pthread_mutex_lock(&arg->c_lock);
    over = arg->ate;
    pthread_mutex_unlock(&arg->c_lock);
    return (over);
}
