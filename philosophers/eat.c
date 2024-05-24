/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:17:24 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 22:24:25 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	fail_get_fork(t_thread *thread)
{
	pthread_mutex_unlock(&thread->mutex->fork_mutex[thread->right_fork]);
	pthread_mutex_unlock(&thread->mutex->fork_mutex[thread->left_fork]);
	return (FALSE);
}

int	get_left_fork(t_thread *thread)
{
	int	idx;
	int	flag;

	idx = thread->left_fork;
	pthread_mutex_lock(&thread->mutex->fork_mutex[idx]);
	if (check_is_exit(thread) == TRUE)
	{
		pthread_mutex_unlock(&thread->mutex->fork_mutex[idx]);
		return (FALSE);
	}
	thread->argument->fork[idx] = 1;
	flag = print_result(thread, FORK);
	if (flag == FALSE)
	{
		pthread_mutex_unlock(&thread->mutex->fork_mutex[idx]);
		return (FALSE);
	}
	if (idx == thread->right_fork)
		return (one_philosopher(thread));
	return (TRUE);
}

int	get_right_fork(t_thread *thread)
{
	int	idx;
	int	flag;

	idx = thread->right_fork;
	pthread_mutex_lock(&thread->mutex->fork_mutex[idx]);
	if (check_is_exit(thread) == TRUE)
		return (fail_get_fork(thread));
	thread->argument->fork[idx] = 1;
	flag = print_result(thread, FORK);
	if (flag == FALSE)
		return (fail_get_fork(thread));
	return (TRUE);
}

void	reset_two_forks(t_thread *thread)
{
	thread->argument->fork[thread->right_fork] = 0;
	pthread_mutex_unlock(&thread->mutex->fork_mutex[thread->right_fork]);
	thread->argument->fork[thread->left_fork] = 0;
	pthread_mutex_unlock(&thread->mutex->fork_mutex[thread->left_fork]);
}

int	eating(t_thread *thread)
{
	int	flag;

	if (get_left_fork(thread) == TRUE && get_right_fork(thread) == TRUE)
	{
		pthread_mutex_lock(&thread->mutex->time);
		thread->eat_time = get_time();
		pthread_mutex_unlock(&thread->mutex->time);
		if (check_is_exit(thread) == TRUE)
			return (fail_get_fork(thread));
		flag = print_result(thread, EATING);
		if (flag == FALSE)
			return (fail_get_fork(thread));
		pthread_mutex_lock(&thread->mutex->end);
		thread->count_eating++;
		pthread_mutex_unlock(&thread->mutex->end);
		ft_usleep(thread->argument->time_to_eat);
		reset_two_forks(thread);
		return (TRUE);
	}
	return (FALSE);
}
