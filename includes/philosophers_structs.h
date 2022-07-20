/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:13:28 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/20 17:27:32 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_STRUCTS_H
# define PHILOSOPHERS_STRUCTS_H

typedef struct s_philo
{
    int timestamp;
    int id;

} t_philo;

typedef struct s_stock
{
    int         stock;
    pthread_t   store_thread;
    pthread_t   client_thread[5];

} t_stock;

static t_stock store =
{
    .stock = 20,
};

#endif
