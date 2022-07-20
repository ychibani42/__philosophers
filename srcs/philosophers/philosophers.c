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



void    __print_philo_status(t_philo *philo, int ac)
{
    int i;

    i = 0;
    memset(philo, 0, sizeof(t_philo) * ac);
    while (i < ac)
    {
        printf("%d %d has taken a fork\n", philo->timestamp, philo->id);
        printf("%d %d is eating\n", philo->timestamp, philo->id);
        printf("%d %d is sleeping\n", philo->timestamp, philo->id);
        printf("%d %d died\n", philo->timestamp, philo->id);
        printf("\n\n");
        i++;
    }
}

int main(int ac, char **av)
{
    t_philo *philo;

    (void)av;
    philo = malloc(sizeof(t_philo) * ac);
    if (!(ac == 5))
        return (__usage(), _ERROR_);
    __print_philo_status(philo, ac);
    free(philo);
}
