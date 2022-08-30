/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:03 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/30 20:35:39 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	simulation(t_program_data *data)
{
	int			i;

	i = 0;
	data->thread_tab = (pthread_t *)malloc(sizeof(pthread_t *)
			* data->infos.nb_philo);
	if (!(data->thread_tab))
		return (-1);
	while (i < data->infos.nb_philo)
	{
		pthread_create(&data->thread_tab[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	return (42);
}

void	simulation_finisher(t_program_data *data)
{
	int	i;

	i = 0;
	while (i < data->infos.nb_philo)
	{
		pthread_join(data->thread_tab[i], NULL);
		i++;
	}
}

int	check_death_global(t_program_data *data)
{
	int	condition;

	condition = 1;
	pthread_mutex_lock(&data->mutex_ressources);
	if (data->die == -1 || data->die == data->infos.nb_philo)
		condition = 0;
	pthread_mutex_unlock(&data->mutex_ressources);
	usleep(1000);
	return (condition);
}

int	main(int ac, char **av)
{
	t_program_data	*data;

	if (parsing(ac, av) == _ERROR_)
		return (_ERROR_);
	data = __init_data(av);
	if (!data)
		return (printf("Malloc Error\n"), _ERROR_);
	simulation(data);
	while (check_death_global(data))
		;
	simulation_finisher(data);
	__clean(data);
	return (_SUCCESS_);
}
