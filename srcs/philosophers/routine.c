/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/25 16:37:21by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	state_printer(int id, char *state, t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_printer);
	if (nobody_died(philo))
	printf("%05li %i %s", exact_time() - philo->start,
			id + 1, state);
	pthread_mutex_unlock(&philo->global->mutex_printer);
}

int		nobody_died(t_philo *philo)
{
	int	condition;

	condition = 1;
	pthread_mutex_lock(&philo->global->mutex_ressources);
	if (philo->global->die == -1)
		condition = 0;
	pthread_mutex_unlock(&philo->global->mutex_ressources);
	return (condition);
}

void	modifier_death(t_philo *philo, int res)
{
	if (res == -1)
		state_printer(philo->id, IS_DEAD, philo);
	pthread_mutex_lock(&philo->global->mutex_ressources);
	if (res == -1)
		philo->global->die = -1;
	if (res == 1 && philo->global->die != -1)
		philo->global->die += 1;
	pthread_mutex_unlock(&philo->global->mutex_ressources);
}

void	sleeping_time(t_philo *philo)
{
	state_printer(philo->id, IS_SLEEPING, philo);
	__usleep(philo->philo_info.time_to_sleep, philo);
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	state_printer(philo->id, IS_THINKING, philo);
	__usleep(1, philo);
	eating_time(philo);
}

void	eating_time(t_philo *philo)
{
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	take_forks(philo);
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	if (nobody_died(philo))
	{
		state_printer(philo->id, IS_EATING, philo);
		__usleep(philo->philo_info.time_to_eat, philo);
	}
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	else
	{
		philo->meal += 1;
		philo->end = exact_time() + philo->philo_info.time_to_die;
	}
	drop_forks(philo);
	if (philo->meal != philo->philo_info.to_feed)
		modifier_death(philo, 1);
	if (nobody_died(philo) && philo->meal != philo->philo_info.to_feed)
		sleeping_time(philo);
}

void *routine(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	while (exact_time() < philo->start)
		;
	philo->end = exact_time() + philo->philo_info.time_to_die;
	if (philo->id % 2 == 1)
		__usleep(philo->philo_info.time_to_eat - 10, philo);
	eating_time(philo);
	return (NULL);
}
