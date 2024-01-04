/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:15:21 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:27:38 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	st_push(t_stack *stack, t_node *node)
{
	t_node	*temp;

	temp = stack->top->next;
	node->prev = stack->top;
	node->next = temp;
	temp->prev = node;
	stack->top->next = node;
	stack->size++;
}

int	pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size == 0)
		return (PASS);
	temp = b->top->next;
	b->top->next->next->prev = b->top;
	b->top->next = b->top->next->next;
	b->size--;
	st_push(a, temp);
	return (PA);
}

int	pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size == 0)
		return (PASS);
	temp = a->top->next;
	a->top->next->next->prev = a->top;
	a->top->next = a->top->next->next;
	st_push(b, temp);
	a->size--;
	return (PB);
}
