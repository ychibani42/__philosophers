/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/23 20:44:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	state_printer(int id, char *state, t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_printer);
	printf("%05li %i %s", exact_time() - philo->start,
			id + 1, state);	
	pthread_mutex_unlock(&philo->global->mutex_printer);
}

int		death_time(t_philo *philo)
{
	int	condition;


	condition = 0;
	pthread_mutex_lock(&philo->global->mutex_ressources);
	if (philo->global->die == DEAD)
		condition = 1;
	pthread_mutex_unlock(&philo->global->mutex_ressources);
	return (condition);
}
void	sleeping_time(t_philo *philo)
{
	state_printer(philo->id, IS_SLEEPING, philo);
	__usleep(philo->philo_info.time_to_sleep);
	state_printer(philo->id, IS_THINKING, philo);
	// if (nobody_died and there is a philo to feed)
	eating_time(philo);
}

void	eating_time(t_philo *philo)
{
	take_forks(philo);
	state_printer(philo->id, IS_EATING, philo);
	__usleep(philo->philo_info.time_to_eat);
	drop_forks(philo);
	// if (nobody_died and there is a philo to feed)
	sleeping_time(philo);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (exact_time() < philo->start)
		;
	eating_time(philo);
	return (NULL);
}
