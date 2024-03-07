/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:47:48 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 20:22:15 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	set_monitor(t_thread **thread, t_argument *arg, t_monitor *monitor,
		t_mutex *m)
{
	int	i;

	i = 0;
	monitor->argument = arg;
	monitor->thread = *thread;
	monitor->is_exit = FALSE;
	monitor->count_ending = 0;
	monitor->mutex = m;
	while (i < arg->n_philo)
	{
		(*thread)[i].is_exit = &monitor->is_exit;
		i++;
	}
}

int	set_mutex(t_mutex *mutex, int n_philo)
{
	int	i;

	mutex->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* n_philo);
	if (mutex->fork_mutex == NULL)
		return (FALSE);
	i = 0;
	while (i < n_philo)
	{
		if (pthread_mutex_init(&mutex->fork_mutex[i], NULL) != TRUE)
			return (mutex_destroy(mutex, n_philo));
		i++;
	}
	if (pthread_mutex_init(&mutex->print, NULL) != TRUE)
		return (mutex_destroy(mutex, n_philo));
	if (pthread_mutex_init(&mutex->time, NULL) != TRUE)
		return (mutex_destroy(mutex, n_philo));
	if (pthread_mutex_init(&mutex->end, NULL) != TRUE)
		return (mutex_destroy(mutex, n_philo));
	return (TRUE);
}

int	check_argument(t_argument *arg)
{
	if (arg->n_philo == 0)
		return (FALSE);
	if (arg->time_to_die == 0)
		return (FALSE);
	if (arg->time_to_eat == 0)
		return (FALSE);
	if (arg->time_to_sleep == 0)
		return (FALSE);
	if (arg->n_eating == 0)
		return (FALSE);
	return (TRUE);
}

int	set_argument(t_argument *arg, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (philo_isnum(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	set_argument_helper(arg, argc, argv);
	arg->init_time = get_time();
	if (arg->init_time == FALSE)
		return (FALSE);
	arg->fork = (int *)malloc(sizeof(int) * arg->n_philo);
	if (arg->fork == NULL)
		return (FALSE);
	memset(arg->fork, 0, sizeof(int) * arg->n_philo);
	if (check_argument(arg) == FALSE)
		return (argument_free(arg));
	return (TRUE);
}

int	set_thread(t_thread **thread, t_argument *arg, t_mutex *m)
{
	int	i;

	(*thread) = (t_thread *)malloc(sizeof(t_thread) * arg->n_philo);
	if ((*thread) == NULL)
		return (thread_destroy(FALSE, thread, arg, m));
	i = 0;
	while (i < arg->n_philo)
	{
		(*thread)[i].left_fork = i;
		if (i != arg->n_philo - 1)
			(*thread)[i].right_fork = i + 1;
		else
			(*thread)[i].right_fork = 0;
		(*thread)[i].argument = arg;
		(*thread)[i].mutex = m;
		(*thread)[i].number = i + 1;
		(*thread)[i].eat_time = get_time();
		(*thread)[i].count_eating = 0;
		(*thread)[i].is_full = FALSE;
		i++;
	}
	return (TRUE);
}
