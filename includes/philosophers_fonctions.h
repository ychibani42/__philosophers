/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_fonctions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:21:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/26 18:58:15 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_FONCTIONS_H
#define PHILOSOPHERS_FONCTIONS_H

/*
**       Parsing
*/

int		parsing(int ac, char **av);


/*
**      Utils
*/

size_t	exact_time(void);


/*
**      Clean
*/

void	__clean(t_program_data *data, t_info infos);


/*
**      Init
*/

t_program_data	*__init_data(char **av);


/*
**		Routine
*/

void	*routine(void *data);

/*
**       Philo
*/

int		main(int ac, char **av);

#endif