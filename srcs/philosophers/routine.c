/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/03 17:49:03 by ychibani         ###   ########.fr       */
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

void	state_printer(size_t time, pthread_mutex_t *printer_mutex, int id, char *state)
{
	pthread_mutex_lock(printer_mutex);
	printf("%zu Philo %d %s\n", exact_time() - time, id + 1, state);
	pthread_mutex_unlock(printer_mutex);
}

void __think(size_t time)
{
	usleep(time);
}

void take_right_fork(t_philo *philo)
{
	while (exact_time() < philo->end)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		if (philo->right_fork->is_taken == _FALSE_)
		{
			philo->right_fork->is_taken = _TRUE_;
			pthread_mutex_unlock(&philo->right_fork->fork);
			break ;
		}
		pthread_mutex_unlock(&philo->right_fork->fork);
	}
	if (exact_time() > philo->end)
		return (you_are_dead(philo, -1));
	state_printer(philo->start, &philo->global->mutex_printer, philo->id, TAKE_FORK);
}

void take_left_fork(t_philo *philo)
{
	while (exact_time() < philo->end)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		if (!philo->left_fork->is_taken)
		{
			philo->left_fork->is_taken = _TRUE_;
			pthread_mutex_unlock(&philo->left_fork->fork);
			break;
		}
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	if (exact_time() > philo->end)
		return (you_are_dead(philo, -1));
	state_printer(philo->start, &philo->global->mutex_printer, philo->id, TAKE_FORK);
}

void take_forks(t_philo *philo)
{
	take_right_fork(philo);
	take_left_fork(philo);
}

void eat(t_philo *philo)
{
	if (exact_time() > philo->end)
		state_printer(philo->start, &philo->global->mutex_printer, philo->id, DIED);
	while (exact_time() < philo->start + philo->philo_info.time_to_eat)
			;
	state_printer(philo->start, &philo->global->mutex_printer, philo->id, IS_EATING);
}

void drop_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->fork);
	fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&fork->fork);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (exact_time() < philo->start)
		;
	if (philo->id % 2 == 0)
		usleep(150);
	while (1)
	{
		if (exact_time() > philo->end)
		{
			state_printer(philo->start, &philo->global->mutex_printer, philo->id, DIED);
			break;
		}
		take_forks(philo);
		eat(philo);
		drop_fork(philo->left_fork);
		drop_fork(philo->right_fork);
	}
	return ((void *)(__intptr_t)_SUCCESS_);
}
