/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_fonctions.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:21:35 by ychibani          #+#    #+#             */
/*   Updated: 2022/08/29 00:16:50 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_FONCTIONS_H
# define PHILOSOPHERS_FONCTIONS_H

/*
**       Parsing
*/

int				parsing(int ac, char **av);
int				int_len(int nb);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
void			ft_putstr_fd(char *str, int fd);
long			_atol_(char *str);

/*
**      Utils
*/

size_t			exact_time(void);
void			state_printer(int id, char *state, t_philo *philo);
void			__usleep(int adding_time, t_philo *philo);
int				nobody_died(t_philo *philo);
void			modifier_death(t_philo *philo, int res);

/*
**      Clean
*/

void			__clean(t_program_data *data);

/*
**      Init
*/

t_program_data	*__init_data(char **av);

/*
**		Routine
*/

void			*routine(void *data);

/*
**		Death
*/

/*
**		Forks action
*/

void			take_right_fork(t_philo *philo);
void			take_left_fork(t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);

/*
**       Philo
*/

void			eating_time(t_philo *philo);
void			sleeping_time(t_philo *philo);
int				main(int ac, char **av);
void			print_data(t_program_data *data);

#endif