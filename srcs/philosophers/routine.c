/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:49:56 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/30 20:45:50 by ychibani         ###   ########.fr       */
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

void	sleeping_time(t_philo *philo)
{
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	state_printer(philo->id, IS_SLEEPING, philo);
	__usleep(philo->philo_info.time_to_sleep, philo);
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	state_printer(philo->id, IS_THINKING, philo);
	eating_time(philo);
}

void	eating_time(t_philo *philo)
{
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	take_forks(philo);
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	philo->end = exact_time() + philo->philo_info.time_to_die;
	if (nobody_died(philo))
	{
		state_printer(philo->id, IS_EATING, philo);
		__usleep(philo->philo_info.time_to_eat, philo);
	}
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	else
		philo->meal += 1;
	drop_forks(philo);
	if (philo->meal != philo->philo_info.to_feed)
		modifier_death(philo, 1);
	if (nobody_died(philo) && philo->meal != philo->philo_info.to_feed)
		sleeping_time(philo);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (exact_time() < philo->start)
		;
	if (philo->philo_info.nb_philo == 1)
		modifier_death(philo, -1);
	philo->end = exact_time() + philo->philo_info.time_to_die;
	if (philo->id % 2 == 1)
		__usleep(philo->philo_info.time_to_eat, philo);
	eating_time(philo);
	return (NULL);
}
