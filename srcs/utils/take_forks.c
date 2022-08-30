/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:41:48 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/30 20:21:41 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	if (!philo->right_fork->is_taken)
		philo->right_fork->is_taken = _TRUE_;
	pthread_mutex_unlock(&philo->right_fork->fork);
	state_printer(philo->id, TAKE_FORK, philo);
}

void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	if (!philo->left_fork->is_taken)
			philo->left_fork->is_taken = _TRUE_;
	pthread_mutex_unlock(&philo->left_fork->fork);
	if (exact_time() > philo->end)
		modifier_death(philo, -1);
	state_printer(philo->id, TAKE_FORK, philo);
}

void	take_forks(t_philo *philo)
{
	if (philo->id == philo->global->infos.nb_philo)
	{
		take_right_fork(philo);
		take_left_fork(philo);
	}
	else
	{
		take_left_fork(philo);
		take_right_fork(philo);
	}	
}
