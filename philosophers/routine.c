/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:00:22 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 22:31:29 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	one_philosopher(t_thread *thread)
{
	ft_usleep(thread->argument->time_to_die);
	return (FALSE);
}

int	check_is_exit(t_thread *thread)
{
	int	ret;

	pthread_mutex_lock(&thread->mutex->end);
	ret = *(thread->is_exit);
	pthread_mutex_unlock(&thread->mutex->end);
	return (ret);
}

int	thinking(t_thread *thread)
{
	int	flag;

	if (check_is_exit(thread) == TRUE)
		return (FALSE);
	flag = print_result(thread, THINKING);
	return (flag);
}

int	sleeping(t_thread *thread)
{
	int	flag;

	if (check_is_exit(thread) == TRUE)
		return (FALSE);
	flag = print_result(thread, SLEEPING);
	if (flag == FALSE)
		return (FALSE);
	ft_usleep(thread->argument->time_to_sleep);
	return (TRUE);
}

void	*routine(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	if (thread->number % 2 == 0)
		ft_usleep(thread->argument->time_to_eat);
	while (check_is_exit(thread) == FALSE)
	{
		if (eating(thread) == FALSE)
			break ;
		if (check_is_exit(thread) == TRUE || sleeping(thread) == FALSE)
			break ;
		if (check_is_exit(thread) == TRUE || thinking(thread) == FALSE)
			break ;
	}
	return (arg);
}
