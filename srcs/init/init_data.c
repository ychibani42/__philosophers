/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:06:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/22 21:46:12 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo *__init_data(char **av)
{
    int     i;
    int     nb_philo;
    t_philo *philo;

    i = 0;
    nb_philo = atol(av[1]);
    philo = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
    if (!philo)
        return (NULL);
    memset(philo, 0, sizeof(t_philo) * nb_philo);
    while (i < nb_philo)
    {
        philo[i].id = (int)i;
        philo[i].die = (int)atol(av[2]);
        philo[i].eat = (int)atol(av[3]);
        philo[i].sleep = (int)atol(av[4]);
        i++;
    }
    return (philo);
}