/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_and_drop_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 17:41:48 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/22 15:58:38 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_right_fork(t_philo *philo)
{
	
		pthread_mutex_lock(&philo->right_fork->fork);
		if (!philo->right_fork->is_taken)
		{
			philo->right_fork->is_taken = _TRUE_;
		}
	state_printer(philo->id, TAKE_FORK, philo);
}

void take_left_fork(t_philo *philo)
{
		pthread_mutex_lock(&philo->left_fork->fork);
		if (!philo->left_fork->is_taken)
		{
			philo->left_fork->is_taken = _TRUE_;
	}
	state_printer(philo->id, TAKE_FORK, philo);
}

void take_forks(t_philo *philo)
{
	take_right_fork(philo);
	take_left_fork(philo);
}

void	drop_right(t_philo *philo)
{
	philo->right_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->right_fork->fork);
}

void	drop_left(t_philo *philo)
{
	philo->left_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	drop_forks(t_philo *philo)
{
	drop_right(philo);
	drop_left(philo);
}