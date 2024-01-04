/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:54:52 by erho              #+#    #+#             */
/*   Updated: 2023/12/26 13:55:56 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	st_rotate(t_stack *stack, t_node *target, t_node *dest)
{
	if (dest == stack->bottom)
	{
		target->next->prev = stack->top;
		stack->top->next = target->next;
		target->prev = dest->prev;
		target->next = dest;
		dest->prev->next = target;
		dest->prev = target;
	}
	else
	{
		target->prev->next = stack->bottom;
		stack->bottom->prev = target->prev;
		target->prev = dest;
		target->next = dest->next;
		dest->next->prev = target;
		dest->next = target;
	}
}
