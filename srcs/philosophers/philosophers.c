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

// void    __usage(void)
// {
//     printf("Usage : ");
//     printf("<number_of_philosophers>");
//     printf(" <time_to_die> <time_to_eat> <time_to_sleep>\n");
// }

// void    __print_philo_status(t_philo *philo, int ac)
// {
//     int i;

//     i = 0;
//     memset(philo, 0, sizeof(t_philo) * ac);
//     while (i < ac)
//     {
//         printf("%d %d has taken a fork\n", philo->timestamp, philo->id);
//         printf("%d %d is eating\n", philo->timestamp, philo->id);
//         printf("%d %d is sleeping\n", philo->timestamp, philo->id);
//         printf("%d %d died\n", philo->timestamp, philo->id);
//         printf("\n\n");
//         i++;
//     }
// }

// int main(int ac, char **av)
// {
//     t_philo *philo;

//     (void)av;
//     philo = malloc(sizeof(t_philo) * ac);
//     if (!(ac == 5))
//         return (__usage(), _ERROR_);
//     __print_philo_status(philo, ac);
//     free(philo);
// }

int get_random(int max)
{
    double val;
    
    val = (double)max * rand();
    val = val / (RAND_MAX + 1.0);

    return ((int)val);
}

void    *ft_store(void *p_data)
{
    while (1)
    {
        if (store.stock <= 0)
        {
            printf("Remplissage du stock de 20\n");
            store.stock = 20;
        }
    }
    (void)p_data;
    return (NULL);
}

void    *ft_clients(void *p_data)
{
    unsigned int nb;
    int val;

    nb = (unsigned long long)p_data;
    while (1)
    {
       val = get_random(6);
       sleep(get_random(3));
       store.stock = store.stock - val;
       printf("Client :%d, prends %d patates du stock, reste %d patates en stock\n", nb, val, store.stock);
    }
}

int main(void)
{
    unsigned long long i;
    int ret;

    i = 0;
    ret = 0; 
    printf("Creation du thread Magasin\n");
    ret = pthread_create(&store.store_thread, NULL, ft_store, NULL);
    if (ret) 
        printf("Impossibilite de cree le thread magasin\n");
    printf("creation des threads clients\n");
    while (i < 5)
    {
        ret = pthread_create(&store.client_thread[i], NULL, ft_clients, (void *)i);
        if (ret)
        {
            printf("Impossibilite de cree le thread client\n");
            return (-1);
        }
        i++;
    }
    i = 0;
    while (i < 5)
    {
        pthread_join(store.client_thread[i], NULL);
        i++;
    }
    pthread_join(store.store_thread, NULL);
    return (1);
}