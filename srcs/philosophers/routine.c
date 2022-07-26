/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/26 18:55:08 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void *eat(void *philo);

// void *think(void *philo)
// {
// }

// void *sleep(void *philo);

// void *die(void *philo)
// {
// 	t_philo *philos;

// 	philos = (t_philo *)philo;
// 	philos->global->die = 1;
// }

// void philosopher(t_philo *philo)
// {
// 	while (1)
// 	{
// 		think(time);
// 		lock();
// 		take(philo->right_fork);
// 		if (!philo->left_fork->is_taken)
// 		{
// 			take(philo->left_fork);
// 			// eat();
// 			put_fork(philo->left_fork);
// 			put_fork(philo->right_fork);
// 			put_fork(philo->right_fork);
// 		}
// 	}
// }

void	*routine(void *data)
{
	t_philo *p_philo;

	p_philo = (t_philo *)data;
	pthread_mutex_lock(&p_philo->global->mutex_printer);
	printf("Salut je suis le philo numero %d\n", p_philo->id);
	pthread_mutex_unlock(&p_philo->global->mutex_printer);
	if (!data)
		return (NULL);
	return (data);
}

