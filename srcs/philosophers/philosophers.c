/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:03 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/19 19:23:34by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


size_t     exact_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        return (_ERROR_);
    return ((size_t)time.tv_usec / 1000 + (size_t)time.tv_sec * 1000);
}


void    __print_philo_status(t_philo *philo, char **av)
{
    int i;

    i = 0;
    while (i < atol(av[1]))
    {
        printf("philo id : %d\n", philo[i].id);
        printf("philo time to die = %lu\n", philo[i].die + exact_time());
        printf("philo time to eat = %lu\n", philo[i].eat + exact_time());
        printf("philo time to sleep = %lu\n", philo[i].sleep + exact_time());
        i++;
    }
}

void    *life(void *philo)
{
    int      i;
    t_philo *philos;

    i = 0;
    philos = (t_philo *)philo;
    pthread_mutex_lock(&philos->mutex);
    while (i < 10)
    {
        if (philos[i].id)
            printf("philo %d is making his life\n", philos[i].id);
        i++;
    }
    pthread_mutex_unlock(&philos->mutex);
    return (NULL);
}

int main(int ac, char **av)
{
    t_philo *philo;
    int     i;

    i = 0;
    if (parsing(ac, av) == _ERROR_)
        return (_ERROR_);

    /*
    ** Initialiser les structs 
    */

    philo = __init_data(av);

    while (i < 10)
    {
        pthread_create(&philo[i].process, NULL, life, (void *)philo);
        i++;
    }

    /*
    **  Lancement de la Simulation
    */
    
    //__simulation_launcher(data);
    __print_philo_status(philo, av);
    while (i < 10)
    {
        pthread_join(philo[i].process, NULL);
        i++;
    }
    free(philo);
}
