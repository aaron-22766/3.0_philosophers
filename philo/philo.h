/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:23:08 by arabenst          #+#    #+#             */
/*   Updated: 2023/07/05 18:41:54 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

# include <string.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* ************************************************************************** */
/*                                   ENUMS                                    */
/* ************************************************************************** */

enum e_return
{
	RETURN_SUCCESS,
	RETURN_FAILURE
};

enum e_errors
{
	ERR_MEM,
	ERR_TOO_FEW_ARGS,
	ERR_TOO_MANY_ARGS,
	ERR_ARG_PHILO,
	ERR_ARG_TT_DIE,
	ERR_ARG_TT_EAT,
	ERR_ARG_TT_SLEEP,
	ERR_ARG_EAT_LIMIT,
	ERR_PTHREAD_CREATE,
	ERR_MUTEX_INIT
};

/* ************************************************************************** */
/*                                  STRUCTS                                   */
/* ************************************************************************** */

struct	s_philo;
struct	s_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	pthread_mutex_t	mtx_eat_count;
	uint64_t		time_last_eaten;
	pthread_mutex_t	mtx_time_last_eaten;
	pthread_mutex_t	*mtx_fork_l;
	pthread_mutex_t	*mtx_fork_r;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				philo_amount;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				eat_limit;
	struct s_philo	*philos;
	pthread_t		*threads;
	pthread_mutex_t	*mtx_forks;
	uint64_t		time_start;
	bool			exit;
	pthread_mutex_t	mtx_exit;
	pthread_mutex_t	mtx_printf;
}	t_data;

/* ************************************************************************** */
/*                                 FUNCTIONS                                  */
/* ************************************************************************** */

// philo.c

// simulation.c
bool		ft_simulation(t_data *data);

// mtx_vars.c
bool		ft_get_exit(t_data *data);
int			ft_get_eat_count(t_philo *philo);
uint64_t	ft_get_time_last_eaten(t_philo *philo);
void		ft_increment_eat_count(t_philo *philo);
void		ft_set_time_last_eaten(t_philo *philo);

// utils.c
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_print_state(t_philo *philo, const char *state);
uint64_t	ft_get_time(uint64_t start);
void		ft_wait(uint64_t ms);

// error.c
void		ft_error(char code);

#endif