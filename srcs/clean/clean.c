/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:05:01 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/29 00:00:41 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__clean(t_program_data *data)
{	
	int	i;

	i = -1;
	while (++i < data->infos.nb_philo)
		pthread_mutex_destroy(&data->forks[i].fork);
	pthread_mutex_destroy(&data->mutex_printer);
	pthread_mutex_destroy(&data->mutex_ressources);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	if (data->thread_tab)
		free(data->thread_tab);
	if (data)
		free(data);
}
