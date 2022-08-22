/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:23:51 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/20 18:36:21 by ychibani         ###   ########.fr       */
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