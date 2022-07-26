/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_structs.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:13:28 by ychibani          #+#    #+#             */
/*   Updated: 2022/07/26 18:48:56 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_STRUCTS_H
#define PHILOSOPHERS_STRUCTS_H

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				is_taken;

} t_fork;

typedef struct s_info
{
	int		nb_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
} t_info;

typedef struct s_philo
{
	int						id;
	pthread_t				process;
	struct s_program_data	*global;
	t_info					philo_info;
	size_t					start;
	size_t					end;
	t_fork					*right_fork;
	t_fork					*left_fork;

} t_philo;

// struct pour les fourchettes
// int take : 1 Pour Oui; 2 Pour Non

typedef struct s_program_data
{
	t_info			infos;
	t_fork			*forks;
	t_philo 		*philos;
	size_t			starting_proccesser;
	int				die;
	pthread_t *thread_tab;
	pthread_mutex_t mutex_printer;
	// pthread_mutex_t mutex_;
} t_program_data;

#endif
