/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:43:44 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:18:29 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_stack *a)
{
	if (a->size == 0)
		return (PASS);
	st_rotate(a, a->top->next, a->bottom);
	return (RA);
}

int	rb(t_stack *b)
{
	if (b->size == 0)
		return (PASS);
	st_rotate(b, b->top->next, b->bottom);
	return (RB);
}

int	rra(t_stack *a)
{
	if (a->size == 0)
		return (PASS);
	st_rotate(a, a->bottom->prev, a->top);
	return (RRA);
}

int	rrb(t_stack *b)
{
	if (b->size == 0)
		return (PASS);
	st_rotate(b, b->bottom->prev, b->top);
	return (RRB);
}
