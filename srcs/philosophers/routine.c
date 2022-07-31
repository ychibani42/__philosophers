/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/31 18:33:16 by ychibani         ###   ########.fr       */
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

void	state_printer(size_t time, int id, char *state)
{
	printf("%zu Philo %d %s\n", time, id, state);
}

void __think(size_t time)
{
	usleep(time);
}

void take_right_fork(t_philo *philo)
{
	if (philo->right_fork->is_taken == _TRUE_)
		return;
	pthread_mutex_lock(&philo->right_fork->fork);
	state_printer(exact_time(), philo->id, TAKE_FORK);
	philo->right_fork->is_taken = _TRUE_;
}

void take_left_fork(t_philo *philo)
{
	if (philo->left_fork->is_taken == _TRUE_)
		return;
	pthread_mutex_lock(&philo->left_fork->fork);
	state_printer(exact_time(), philo->id, TAKE_FORK);
	philo->left_fork->is_taken = _TRUE_;
}

void take_forks(t_philo *philo)
{
	take_right_fork(philo);
	take_left_fork(philo);
}

void eat(t_philo *philo)
{
	state_printer(exact_time(), philo->id, IS_EATING);
	while (exact_time() > philo->philo_info.time_to_eat)
			;
	if (exact_time() > philo->end)
	{
		state_printer(exact_time(), philo->id, DIED);
		exit(1);
	}
}

void put_fork(t_fork *fork)
{
	fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&fork->fork);
}

// void philosopher(t_philo *philo)
// {
// 	while (1)
// 	{
// 		think(philo->info.time_to_sleep);
// pthread_mutex_lock(&philo->right_fork->fork);
// 		take(philo->right_fork);
// 		if (!philo->left_fork->is_taken && philo->id % 2 == 0)
// 		{
// pthread_mutex_lock(&philo->left_fork->fork);
// 			take(philo->left_fork);
// 			// eat();
// 			put_fork(philo->left_fork);
// 			put_fork(philo->right_fork);
// pthread_mutex_unlock(&philo->right_fork->fork);
// 		}
// else if (philo->id % 2 != 0)
// {

// }
// put_fork(philo->right_fork);
// pthread_mutex_unlock(&philo->right_fork->fork);
// if (!philo->global->nb_eater)
// break;
// nb_eater--;
// 	}
// }

void *routine(void *data)
{
	t_philo *p_philo;

	p_philo = (t_philo *)data;
	while (1)
	{
		__think(500);
		take_right_fork(p_philo);
		if (!p_philo->left_fork->is_taken && p_philo->id % 2 == 0)
		{
			take_left_fork(p_philo);
			eat(p_philo);
		}
		put_fork(p_philo->right_fork);
		put_fork(p_philo->left_fork);
	}

	pthread_mutex_lock(&p_philo->global->mutex_printer);
	printf("Salut je suis le philo numero %d\n", p_philo->id);
	pthread_mutex_unlock(&p_philo->global->mutex_printer);
	return ((void *)(__intptr_t)42);
}
