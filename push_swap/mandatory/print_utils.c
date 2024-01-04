/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:26:50 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:26:56 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_command(int command_no)
{
	if (command_no == SA)
		ft_printf("sa\n");
	else if (command_no == SB)
		ft_printf("sb\n");
	else if (command_no == PA)
		ft_printf("pa\n");
	else if (command_no == PB)
		ft_printf("pb\n");
	else if (command_no == RA)
		ft_printf("ra\n");
	else if (command_no == RB)
		ft_printf("rb\n");
	else if (command_no == SS)
		ft_printf("ss\n");
	else if (command_no == RR)
		ft_printf("rr\n");
	else if (command_no == RRA)
		ft_printf("rra\n");
	else if (command_no == RRB)
		ft_printf("rrb\n");
	else if (command_no == RRR)
		ft_printf("rrr\n");
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
