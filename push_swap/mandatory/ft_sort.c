/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:49:13 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 19:12:38 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	t_node	*node;
	int		max_data;

	node = stack->top->next;
	max_data = find_max_node(stack)->data;
	if (node->data == max_data)
		print_command(ra(stack));
	else if (node->next->data == max_data)
		print_command(rra(stack));
	node = stack->top->next;
	if (node->data > node->next->data)
		print_command(sa(stack));
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*node;

	while (a->size > 3)
	{
		if (b->size <= 1)
			print_command(pb(a, b));
		else
		{
			set_idx(a);
			set_idx(b);
			set_target_in_a(a, b);
			set_cost_a(a, b);
			node = find_min_cost_node(a);
			move_a_and_b(a, node, b, node->target);
			move_top(a, node, b, node->target);
			print_command(pb(a, b));
		}
	}
	sort_three(a);
}

void	min_will_be_top(t_stack *a)
{
	t_check	check;
	t_node	*min;

	min = find_min_node(a);
	check.mid_a = a->size / 2;
	check.is_mid_a_up = min->idx <= check.mid_a;
	if (check.is_mid_a_up)
	{
		while (a->top->next != min)
			print_command(ra(a));
	}
	else
	{
		while (a->top->next != min)
			print_command(rra(a));
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*node;

	while (b->size > 0)
	{
		set_idx(a);
		set_idx(b);
		set_target_in_b(b, a);
		set_cost_b(a, b);
		node = find_min_cost_node(b);
		move_top(a, node->target, b, node);
		print_command(pa(a, b));
	}
	set_idx(a);
	min_will_be_top(a);
}
