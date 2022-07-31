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

size_t	exact_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (_ERROR_);
	return ((size_t)time.tv_usec / 1000 + (size_t)time.tv_sec * 1000);
}

void	print_data(t_program_data *data)
{
	// printf("%d\n", data->infos.nb_philo);
	// printf("%zu\n", data->infos.time_to_die);
	// printf("%zu\n", data->infos.time_to_eat);
	// printf("%zu\n", data->infos.time_to_sleep);
	for (int i = 0; i < data->infos.nb_philo; i++)
	{
		printf("%d\n", data->philos[i].id);
		printf("%zu\n", data->philos[i].start);
		//     printf("%d\n", data->philos[i].right_fork->is_taken);
		//     printf("%d\n", data->philos[i].left_fork->is_taken);
	}
	printf("%zu\n", data->starting_proccesser);
	printf("%d\n", data->die);
}


int __simulation(t_program_data *data)
{
	int			i;

	i = 0;
	data->thread_tab = (pthread_t *)malloc(sizeof(pthread_t *) * data->infos.nb_philo);
	if (!(data->thread_tab))
		return (-1);
	while (i < data->infos.nb_philo)
	{
		pthread_create(&data->thread_tab[i], NULL, &routine, &data->philos[i]);
		i++;
	}
	return (42);
}

int	__simulation_finisher(t_program_data *data)
{
	int ret;
    int i;

    i = 0;
    while (i < data->infos.nb_philo)
    {
		ret = pthread_join(data->thread_tab[i], &data->status);
        i++;
    }
	pthread_mutex_destroy(&data->mutex_printer);
	__clean(data, data->infos);
	return (ret);
}

int main(int ac, char **av)
{
	t_program_data	*data;
	int				ret;

	if (parsing(ac, av) == _ERROR_)
		return (_ERROR_);
	data = __init_data(av);
	if (!data)
		return (_ERROR_);
	__simulation(data);
	ret = __simulation_finisher(data);
	return (ret);
}
