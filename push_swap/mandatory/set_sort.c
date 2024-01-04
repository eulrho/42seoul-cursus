/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:46:20 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 19:12:59 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_idx(t_stack *stack)
{
	t_node			*node;
	unsigned int	idx;

	node = stack->top->next;
	idx = 0;
	while (node != stack->bottom)
	{
		node->idx = idx;
		node = node->next;
		idx++;
	}
}

void	set_target_in_a(t_stack *current, t_stack *dest)
{
	t_node	*node;
	t_node	*temp;
	t_node	*target;

	node = current->top->next;
	while (node != current->bottom)
	{
		target = NULL;
		temp = dest->top->next;
		while (temp != dest->bottom)
		{
			if (node->data > temp->data && (target == NULL
					|| target->data < temp->data))
				target = temp;
			temp = temp->next;
		}
		if (target == NULL)
			target = find_max_node(dest);
		node->target = target;
		node = node->next;
	}
}

void	set_target_in_b(t_stack *current, t_stack *dest)
{
	t_node	*node;
	t_node	*temp;
	t_node	*target;

	node = current->top->next;
	while (node != current->bottom)
	{
		target = NULL;
		temp = dest->top->next;
		while (temp != dest->bottom)
		{
			if (node->data < temp->data && (target == NULL
					|| target->data > temp->data))
				target = temp;
			temp = temp->next;
		}
		if (target == NULL)
			target = find_min_node(dest);
		node->target = target;
		node = node->next;
	}
}

t_check	set_check(t_stack *a, t_node *first, t_stack *b, t_node *second)
{
	t_check	res;

	res.mid_a = a->size / 2;
	res.mid_b = b->size / 2;
	res.is_mid_a_up = first->idx <= res.mid_a;
	res.is_mid_b_up = second->idx <= res.mid_b;
	return (res);
}
