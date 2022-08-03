/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:35:18 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/03 17:49:09 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	you_are_dead(t_philo *philo, int bool)
{
	if (bool)
		state_printer(philo->start, &philo->global->mutex_printer, philo->id, DIED);
}
