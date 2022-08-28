/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:35:18 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/28 23:12:15 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	nobody_died(t_philo *philo)
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
