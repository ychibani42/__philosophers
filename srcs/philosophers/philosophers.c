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


size_t     exact_time(void)
{
    struct timeval time;

    if (gettimeofday(&time, NULL) == -1)
        return (_ERROR_);
    return ((size_t)time.tv_usec / 1000 + (size_t)time.tv_sec * 1000);
}



int main(int ac, char **av)
{
    t_program_data *data;
    if (parsing(ac, av) == _ERROR_)
        return (_ERROR_);
    /*
    ** Initialiser les structs 
    */
    data = __init_data(av);
    /*
    **  Lancement de la Simulation
    */
    //__simulation_launcher(data);
    // __print_philo_status(philo, av);
    free(data);
}
