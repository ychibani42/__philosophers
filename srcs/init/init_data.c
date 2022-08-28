/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:06:13 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/25 16:21:34by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	__get_info(char **av)
{
	t_info	info_to_return;
	int		i;
	int		nb_philos;

	i = 0;
	nb_philos = atol(av[1]);
	memset(&info_to_return, 0, sizeof(info_to_return));
	info_to_return.nb_philo = nb_philos;
	info_to_return.time_to_die = atol(av[2]);
	info_to_return.time_to_eat = atol(av[3]);
	info_to_return.time_to_sleep = atol(av[4]);
	if (!av[5])
		info_to_return.to_feed = -1;
	else
		info_to_return.to_feed = atol(av[5]);
	return (info_to_return);
}

t_philo *__init_philos(t_program_data *data, t_info infos)
{
	int		i;
	t_philo *philos;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * infos.nb_philo);
	if (!philos)
		return (NULL);
	memset(philos, 0, sizeof(t_philo) * infos.nb_philo);
	while (i < infos.nb_philo)
	{
		philos[i].id = i;
		philos[i].meal = 0;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % infos.nb_philo];
		philos[i].start = data->starting_proccesser;
		philos[i].end = data->starting_proccesser + infos.time_to_die;
		philos[i].philo_info = infos;
		philos[i].global = data;
		i++;
	}
	return (philos);
}

t_fork *__init_forks_table(t_info infos)
{
	t_fork *fork_table;
	int		i;

	i = 0;
	fork_table = (t_fork *)malloc(sizeof(t_fork) * infos.nb_philo);
	if (!fork_table)
		return (NULL);
	memset(fork_table, 0, infos.nb_philo);
	while (i < infos.nb_philo)
	{
		pthread_mutex_init(&fork_table[i].fork, NULL);
		fork_table[i].is_taken = _FALSE_;
		i++;
	}
	return (fork_table);
}

t_program_data *__init_data(char **av)
{
	t_program_data *data;
	int		i;

	i = 0;
	data = (t_program_data *)malloc(sizeof(t_program_data));
	if (!data)
		return (NULL);
	data->starting_proccesser = exact_time() + 100;
	data->infos = __get_info(av);
	data->forks = __init_forks_table(data->infos);
	data->philos = __init_philos(data, data->infos);
	data->die = 1;
	if (!data->philos || !data->forks)
		return (__clean(data, data->infos), NULL);
    pthread_mutex_init(&data->mutex_printer, NULL);
    pthread_mutex_init(&data->mutex_ressources, NULL);
	return (data);
}
