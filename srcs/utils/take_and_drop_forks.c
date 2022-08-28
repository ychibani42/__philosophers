/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:41:48 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/25 17:06:15by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_right_fork(t_philo *philo)
{
	while (exact_time() < philo->end)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		if (!philo->right_fork->is_taken)
		{
			philo->right_fork->is_taken = _TRUE_;
			pthread_mutex_unlock(&philo->right_fork->fork);
			break ;
		}
		pthread_mutex_unlock(&philo->right_fork->fork);
	}
	state_printer(philo->id, TAKE_FORK, philo);
}

void take_left_fork(t_philo *philo)
{
	while (exact_time() <= philo->end + 1) 
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
		modifier_death(philo, -1);
	state_printer(philo->id, TAKE_FORK, philo);
}

void take_forks(t_philo *philo)
{
		take_right_fork(philo);
		take_left_fork(philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	philo->right_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_lock(&philo->left_fork->fork);
	philo->left_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->left_fork->fork);
}