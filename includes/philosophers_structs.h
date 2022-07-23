/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:13:28 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/23 21:56:20 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_STRUCTS_H
#define PHILOSOPHERS_STRUCTS_H

typedef struct s_fork
{
	pthread_t	fork;
	int			is_taken;
	// 1 ou 0

} t_fork;

typedef struct s_info
{
	int		nb_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
};

typedef struct s_philo
{
	
	// pthread_mutex_t	mutex;
	int				id;
	pthread_t		process;
	struct s_program_data *global;
	t_info			philo_info;
	size_t			start;
	size_t			end;
	t_fork			*right_fork;
	t_fork			*left_fork;

} t_philo;

// struct pour les fourchettes
// int take : 1 Pour Oui; 2 Pour Non

typedef struct s_program_data
{
	t_philo			*all_philos;
	t_info			infos;
	t_fork			*fork_table;
	t_philo 		*philo_table;
	int				die;
	size_t			starting_proccesser;
	int				time_of_death;
	int				time_of_start;

} t_program_data;

#endif
