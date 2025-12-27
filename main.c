#include "philo.h"

void for_thread(t_arg *arg, t_philo *philo)
{
    int i;

    i = 0;
    arg->start_time = for_time();
    while (i < arg->num_of_philo)
    {
        pthread_mutex_lock(&arg->philo[i].meal);
        arg->philo[i].last_eat = arg->start_time;
        pthread_mutex_unlock(&arg->philo[i].meal);
        pthread_create(&philo[i].t_id, NULL, ft, &philo[i]);
        i++;
    }
    pthread_create(&arg->check, NULL, check, arg);
}

int main(int ac, char **av)
{
    t_arg *arg;
    t_philo *philo;
    int i;

    arg_check(ac, av);
    arg = placement(ac, av);
    pthread_mutex_init(&arg->print_w, NULL);
    pthread_mutex_init(&arg->dpn_lock, NULL);
    pthread_mutex_init(&arg->c_lock, NULL);
    for_fork(arg);
    philo = for_philo(arg);
    for_thread(arg, philo);
    pthread_join(arg->check, NULL);
    i = -1;
    while (++i < arg->num_of_philo)
        pthread_join(philo[i].t_id, NULL);
    for_destroy(arg);
    free(arg->fork);
    free(arg->philo);
    free(arg);
}
