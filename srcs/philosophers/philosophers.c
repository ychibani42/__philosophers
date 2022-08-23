/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:03 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/19 19:23:34by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int simulation(t_program_data *data)
{
	int			i;

	i = 0;
	data->thread_tab = (pthread_t *)malloc(sizeof(pthread_t *) * data->infos.nb_philo);
	if (!(data->thread_tab))
		return (-1);
	while (i < data->infos.nb_philo)
	{
		if (i % 2 == 0)
			pthread_create(&data->thread_tab[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	i = 0;
	__usleep(data->infos.time_to_eat);
	while (i < data->infos.nb_philo)
	{
		if (i % 2 != 0)
			pthread_create(&data->thread_tab[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	return (42);
}

int	simulation_finisher(t_program_data *data)
{
	int ret;
    int i;

    i = 0;
    while (i < data->infos.nb_philo)
    {
		ret = pthread_join(data->thread_tab[i], &data->status);
        i++;
    }
	__clean(data, data->infos);
	return (ret);
}

/*
void	dead_philo_exit(t_philo *philo)
{
	// exit_all;
	// state_printer(philo->id, IS_DEAD, philo);
}

void	check_death(t_program_data *data)
{
	while (ALIVE)
	{
		if (data->die == DEAD)
			dead_philo_exit();
	}
}
*/

int main(int ac, char **av)
{
	t_program_data	*data;
	int				ret;

	if (parsing(ac, av) == _ERROR_)
		return (_ERROR_);
	data = __init_data(av);
	if (!data)
		return (printf("Malloc Error\n"), _ERROR_);
	simulation(data);
	check_death(data);
	ret = simulation_finisher(data);
	return (ret);
}
