/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:51 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/23 19:34:46 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__usleep(int adding_time)
{
	size_t time;

	time = exact_time() + adding_time;
	if (adding_time)
	{
		while (exact_time() < time)
			usleep(100);
	}
}

size_t	exact_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (_ERROR_);
	return ((size_t)time.tv_usec / 1000 + (size_t)time.tv_sec * 1000);
}

void	print_data(t_program_data *data)
{
	pthread_mutex_lock(&data->mutex_printer);
	printf("nombre de philos : %d\n", data->infos.nb_philo);
	printf("temps avant de mourir %zu\n", data->infos.time_to_die);
	printf("temps pour manger %zu\n", data->infos.time_to_eat);
	printf("temps pour dormir %zu\n", data->infos.time_to_sleep);
	for (int i = 0; i < data->infos.nb_philo; i++)
	{
		printf("philo numero : %d\n", data->philos[i].id);
		printf("commencement des simulations : %zu\n", data->philos[i].start);
		printf("etat de la fourchette de droite : %d\n", data->philos[i].right_fork->is_taken);
		printf("etat de la fourchette de gauche : %d\n", data->philos[i].left_fork->is_taken);
	}
	printf("commencement : %zu\n", data->starting_proccesser);
	printf("fin de simulation : %d\n", data->die);
	pthread_mutex_unlock(&data->mutex_printer);
}

