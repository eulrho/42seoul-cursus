/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:19:02 by erho              #+#    #+#             */
/*   Updated: 2024/03/04 21:39:20 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	argument_free(t_argument *arg)
{
	free(arg->fork);
	return (FALSE);
}

int	mutex_destroy(t_mutex *mutex, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		pthread_mutex_destroy(&mutex->fork_mutex[i]);
		i++;
	}
	if (mutex->fork_mutex != NULL)
		free(mutex->fork_mutex);
	pthread_mutex_destroy(&mutex->print);
	pthread_mutex_destroy(&mutex->time);
	pthread_mutex_destroy(&mutex->end);
	return (FALSE);
}

int	thread_destroy(int flag, t_thread **thread, t_argument *arg, t_mutex *m)
{
	int	n_philo;

	n_philo = arg->n_philo;
	mutex_destroy(m, n_philo);
	argument_free(arg);
	if (*thread != NULL)
		free(*thread);
	return (flag);
}
