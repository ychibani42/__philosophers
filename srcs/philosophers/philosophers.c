/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:03 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/18 20:45:32 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    __usage(void)
{
    printf("Usage : ");
    printf("<number_of_philosophers>");
    printf(" <time_to_die> <time_to_eat> <time_to_sleep>\n");
}

int main(int ac, char **av)
{
    (void)av;
    if (!(ac == 5))
        return (__usage(), _ERROR_);
}