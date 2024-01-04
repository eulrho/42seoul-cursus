/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:07:53 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:26:26 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc >= 2)
	{
		a = stack_init();
		b = stack_init();
		setting(a, argc, argv);
		if (is_sorted(a) == 0)
		{
			if (a->size == 2)
				print_command(sa(a));
			else if (a->size == 3)
				sort_three(a);
			else
			{
				move_a_to_b(a, b);
				move_b_to_a(a, b);
			}
		}
		exit(0);
	}
	return (0);
}
