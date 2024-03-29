/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:51 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/30 20:45:35 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	__usleep(int adding_time, t_philo *philo)
{
	size_t	time;
	size_t	final_time;

	time = exact_time() + adding_time;
	final_time = time - exact_time();
	if (adding_time)
	{
		while (exact_time() < time
			&& nobody_died(philo)
			&& exact_time() <= philo->end)
		{
			if (final_time > 100)
				usleep(80);
			else
				usleep(final_time / 10);
		}
	}
}

size_t	exact_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (_ERROR_);
	return ((size_t)time.tv_usec / 1000 + (size_t)time.tv_sec * 1000);
}
