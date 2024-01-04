/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:58:27 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:24:32 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_node(t_stack *stack, int data)
{
	t_node	*node;

	node = stack->top->next;
	while (node != stack->bottom)
	{
		if (node->data == data)
			print_error();
		node = node->next;
	}
}

unsigned int	find_max(unsigned int a, unsigned int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_node	*find_max_node(t_stack *stack)
{
	t_node	*node;
	t_node	*max_data;

	node = stack->top->next;
	max_data = node;
	while (node != stack->bottom)
	{
		if (max_data->data < node->data)
			max_data = node;
		node = node->next;
	}
	return (max_data);
}

t_node	*find_min_node(t_stack *stack)
{
	t_node	*node;
	t_node	*min_data;

	node = stack->top->next;
	min_data = node;
	while (node != stack->bottom)
	{
		if (min_data->data > node->data)
			min_data = node;
		node = node->next;
	}
	return (min_data);
}

t_node	*find_min_cost_node(t_stack *stack)
{
	t_node	*node;
	t_node	*min_cost;

	node = stack->top->next;
	min_cost = node;
	while (node != stack->bottom)
	{
		if (min_cost->cost > node->cost)
			min_cost = node;
		node = node->next;
	}
	return (min_cost);
}
