/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:20:56 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:28:32 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top->next;
	while (node->next != stack->bottom)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

void	move_a_and_b(t_stack *a, t_node *first, t_stack *b, t_node *second)
{
	t_check			check;

	check = set_check(a, first, b, second);
	if (check.is_mid_a_up && check.is_mid_b_up)
	{
		while (first != a->top->next && second != b->top->next)
		{
			ra(a);
			rb(b);
			print_command(RR);
		}
	}
	else if (!(check.is_mid_a_up) && !(check.is_mid_b_up))
	{
		while (first != a->top->next && second != b->top->next)
		{
			rra(a);
			rrb(b);
			print_command(RRR);
		}
	}
}

void	move_top(t_stack *a, t_node *first, t_stack *b, t_node *second)
{
	t_check			check;

	check = set_check(a, first, b, second);
	while (check.is_mid_a_up && first != a->top->next)
		print_command(ra(a));
	while (!(check.is_mid_a_up) && first != a->top->next)
		print_command(rra(a));
	while (check.is_mid_b_up && second != b->top->next)
		print_command(rb(b));
	while (!(check.is_mid_b_up) && second != b->top->next)
		print_command(rrb(b));
}
