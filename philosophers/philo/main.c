/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:36:01 by erho              #+#    #+#             */
/*   Updated: 2024/03/04 21:20:17 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_argument	arg;
	t_mutex		m;
	t_thread	*thread;
	t_monitor	monitor;

	if (argc != 5 && argc != 6)
		return (FALSE);
	if (set_argument(&arg, argc, argv) == FALSE)
		return (FALSE);
	if (set_mutex(&m, arg.n_philo) == FALSE)
		return (argument_free(&arg));
	if (set_thread(&thread, &arg, &m) == FALSE)
		return (FALSE);
	set_monitor(&thread, &arg, &monitor, &m);
	if (run_thread(thread, &monitor) == FALSE)
		return (thread_destroy(FALSE, &thread, &arg, &m));
	return (thread_destroy(TRUE, &thread, &arg, &m));
}
