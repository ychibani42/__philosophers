/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_fonctions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:21:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/24 16:05:47 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_FONCTIONS_H
# define PHILOSOPHERS_FONCTIONS_H

/*
**       Parsing
*/

int     parsing(int ac, char **av);


t_program_data *__init_data(char **av);

/*
**       Philo
*/

int     main(int ac, char **av);

#endif