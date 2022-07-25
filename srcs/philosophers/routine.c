/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/25 16:58:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *eat(void *philo);

void *think(void *philo)
{
    
}

void *sleep(void *philo);

void *die(void *philo)
{
    t_philo philos;

    philos = (t_philo *)philo;
    philos.die = 1;
}

void philosopher(t_philo *philo)
{
    while (1)
    {
        think(time);
        lock();
        take(philo->right_fork);
        if (!philo->left_fork->is_taken)
        {
            take(philo->left_fork);
            eat();
            put_fork(philo->left_fork);
            put_fork(philo->right_fork);
            put_fork(philo->right_fork);
    }
}