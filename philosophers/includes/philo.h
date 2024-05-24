/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:37:07 by erho              #+#    #+#             */
/*   Updated: 2024/03/06 16:12:16 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 0
# define FALSE -1
# define FORK 2
# define EATING 3
# define SLEEPING 4
# define THINKING 5
# define DEAD 6

typedef struct s_mutex
{
	pthread_mutex_t	time;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	end;
}	t_mutex;

typedef struct s_argument
{
	ssize_t	init_time;
	int		n_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_eating;
	int		*fork;
}	t_argument;

typedef struct s_thread
{
	int			count_eating;
	ssize_t		eat_time;
	t_argument	*argument;
	t_mutex		*mutex;
	int			left_fork;
	int			right_fork;
	int			number;
	pthread_t	th;
	int			*is_exit;
	int			is_full;
}	t_thread;

typedef struct s_monitor
{
	t_mutex		*mutex;
	pthread_t	mt;
	t_argument	*argument;
	t_thread	*thread;
	int			is_exit;
	int			count_ending;
}	t_monitor;

// utils
int		philo_atoi(const char *str);
int		philo_isnum(char *str);
void	ft_usleep(int time);

// set
int		set_argument(t_argument *arg, int argc, char **argv);
int		set_mutex(t_mutex *mutex, int n_philo);
int		set_thread(t_thread **thread, t_argument *arg, t_mutex *m);
void	set_monitor(t_thread **thread, t_argument *arg,
			t_monitor *monitor, t_mutex *m);
void	set_argument_helper(t_argument *arg, int argc, char **argv);

// run
int		run_thread(t_thread *thread, t_monitor *monitor);
int		print_result(t_thread *thread, int status);
ssize_t	get_time(void);
ssize_t	get_print_time(t_thread *thread);

// routine
void	*routine(void *arg);
int		check_is_exit(t_thread *thread);
int		one_philosopher(t_thread *thread);

// monitoring
void	*monitor_routine(void *arg);

// free
int		mutex_destroy(t_mutex *mutex, int n_philo);
int		thread_destroy(int flag, t_thread **thread, t_argument *arg,
			t_mutex *m);
int		argument_free(t_argument *arg);

// eat
int		eating(t_thread *thread);

#endif
