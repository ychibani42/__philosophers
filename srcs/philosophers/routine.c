/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/19 18:03:04 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	state_printer(size_t time, pthread_mutex_t *printer_mutex, 
							int id, char *state)
{
	pthread_mutex_lock(printer_mutex);
	printf("%zu philo %d %s\n", time, id, state);
	pthread_mutex_unlock(printer_mutex);
}

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	philo->right_fork->is_taken = _TRUE_;
	state_printer(philo->end - exact_time(), &philo->global->mutex_printer, philo->id, "take right fork\n");
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	philo->left_fork->is_taken = _TRUE_;
	state_printer(philo->end - exact_time(), &philo->global->mutex_printer, philo->id, "take left fork\n");
}

void	take_forks(t_philo *philo)
{
	take_left_fork(philo);
	take_right_fork(philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (exact_time() < philo->start)
		;
	philo->end = exact_time() + philo->philo_info.time_to_die;
	if (philo->id % 2 == 1)
		usleep(10000);
	while (1)
	{
		take_forks(philo);
		state_printer(exact_time() - philo->start, &philo->global->mutex_printer, philo->id, IS_EATING);
		usleep(philo->philo_info.time_to_sleep);
		drop_forks(philo);
	}
	return ((void *)(__intptr_t)_SUCCESS_);
}
