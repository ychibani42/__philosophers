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


void    __print_philo_status(t_philo *philo, char **av)
{
    int i;

    i = 0;
    while (i < atol(av[1]))
    {
        printf("philo id : %d\n", philo[i].id);
        printf("philo time to die = %d\n", philo[i].die);
        printf("philo time to eat = %d\n", philo[i].eat);
        printf("philo time to eat = %d\n", philo[i].sleep);
        i++;
    }
}

int main(int ac, char **av)
{
    t_philo *philo;

    if (parsing(ac, av) == _ERROR_)
        return (_ERROR_);
    philo = __init_data(av);
    __print_philo_status(philo, av);
    free(philo);
}
