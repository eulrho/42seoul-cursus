/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:03:29 by erho              #+#    #+#             */
/*   Updated: 2024/03/05 20:22:29 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	set_argument_helper(t_argument *arg, int argc, char **argv)
{
	arg->n_philo = philo_atoi(argv[1]);
	arg->time_to_die = philo_atoi(argv[2]);
	arg->time_to_eat = philo_atoi(argv[3]);
	arg->time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		arg->n_eating = philo_atoi(argv[5]);
	else
		arg->n_eating = FALSE;
}
