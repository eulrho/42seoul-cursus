/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 19:11:13 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 19:11:55 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_cost_a(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_check	check;

	node = a->top->next;
	while (node != a->bottom)
	{
		check = set_check(a, node, b, node->target);
		node->cost = 1;
		if (check.is_mid_a_up && check.is_mid_b_up)
			node->cost += find_max(node->idx, node->target->idx);
		else if (check.is_mid_a_up && !(check.is_mid_b_up))
			node->cost += node->idx + b->size - node->target->idx;
		else if (!(check.is_mid_a_up) && check.is_mid_b_up)
			node->cost += a->size - node->idx + node->target->idx;
		else
			node->cost += find_max(a->size - node->idx,
					b->size - node->target->idx);
		node = node->next;
	}
}

void	set_cost_b(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_check	check;

	node = b->top->next;
	while (node != b->bottom)
	{
		check = set_check(a, node->target, b, node);
		node->cost = 1;
		if (check.is_mid_a_up && check.is_mid_b_up)
			node->cost += find_max(node->target->idx, node->idx);
		else if (check.is_mid_a_up && !(check.is_mid_b_up))
			node->cost += node->target->idx + b->size - node->idx;
		else if (!(check.is_mid_a_up) && check.is_mid_b_up)
			node->cost += a->size - node->target->idx + node->idx;
		else
			node->cost += find_max(a->size - node->target->idx,
					b->size - node->idx);
		node = node->next;
	}
}
