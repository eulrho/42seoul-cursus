/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:38:40 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 22:40:45 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

ssize_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != TRUE)
		return (FALSE);
	return ((ssize_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

ssize_t	get_print_time(t_thread *thread)
{
	ssize_t	temp;

	pthread_mutex_lock(&thread->mutex->time);
	temp = get_time() - thread->argument->init_time;
	pthread_mutex_unlock(&thread->mutex->time);
	return (temp);
}

void	join_threads(t_thread *thread, t_monitor *monitor)
{
	int	i;

	i = 0;
	pthread_join(monitor->mt, NULL);
	while (i < thread->argument->n_philo)
	{
		pthread_join(thread[i].th, NULL);
		i++;
	}
}

int	print_result(t_thread *thread, int status)
{
	ssize_t	time;

	if (check_is_exit(thread) == TRUE)
		return (FALSE);
	pthread_mutex_lock(&thread->mutex->print);
	if (check_is_exit(thread) == TRUE)
	{
		pthread_mutex_unlock(&thread->mutex->print);
		return (FALSE);
	}
	time = get_print_time(thread);
	if (status == FORK)
		printf("%zd %d has taken a fork\n", time, thread->number);
	else if (status == EATING)
		printf("%zd %d is eating\n", time, thread->number);
	else if (status == SLEEPING)
		printf("%zd %d is sleeping\n", time, thread->number);
	else if (status == THINKING)
		printf("%zd %d is thinking\n", time, thread->number);
	else
		printf("%zd %d died\n", time, thread->number);
	pthread_mutex_unlock(&thread->mutex->print);
	return (TRUE);
}

int	run_thread(t_thread *thread, t_monitor *monitor)
{
	int	i;

	i = 0;
	if (pthread_create(&monitor->mt, NULL, monitor_routine,
			(void *)monitor) != TRUE)
		return (FALSE);
	while (i < thread->argument->n_philo)
	{
		if (pthread_create(&thread[i].th, NULL, routine, (void *)&thread[i])
			!= TRUE)
			break ;
		i++;
	}
	join_threads(thread, monitor);
	return (TRUE);
}
