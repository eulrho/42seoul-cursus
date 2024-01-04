/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:31:43 by erho              #+#    #+#             */
/*   Updated: 2024/01/03 21:48:09 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	st_swap(t_stack *stack)
{
	t_node	*node;

	node = stack->top->next;
	node->next->prev = stack->top;
	stack->top->next = node->next;
	node->prev = node->next;
	node->next->next->prev = node;
	node->next = node->next->next;
	stack->top->next->next = node;
}

int	sa(t_stack *a)
{
	if (a->size < 2)
		return (PASS);
	st_swap(a);
	return (SA);
}

int	sb(t_stack *b)
{
	if (b->size < 2)
		return (PASS);
	st_swap(b);
	return (SB);
}
