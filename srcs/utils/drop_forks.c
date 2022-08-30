/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:20:41 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/30 20:20:52 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	philo->right_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->right_fork->fork);
}

void	drop_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	philo->left_fork->is_taken = _FALSE_;
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	drop_forks(t_philo *philo)
{
	if (philo->id == philo->global->infos.nb_philo)
	{
		drop_right_fork(philo);
		drop_left_fork(philo);
	}
	else
	{
		drop_left_fork(philo);
		drop_right_fork(philo);
	}
}
