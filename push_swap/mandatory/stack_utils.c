/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:07:58 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 14:28:58 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		print_error();
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	node->cost = 0;
	node->idx = 0;
	return (node);
}

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		print_error();
	stack->top = create_node(0);
	stack->bottom = create_node(0);
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->size = 0;
	return (stack);
}

void	case_split(t_stack *stack, char **argv)
{
	t_node	*node;
	char	**splited_str;
	size_t	len;
	int		data;

	splited_str = ft_split(argv[1], ' ');
	len = ft_two_dim_len(splited_str);
	if (len == 0)
		print_error();
	while (len >= 1)
	{
		--len;
		if (splited_str[len][0] == '\0')
			print_error();
		data = push_swap_atoi(splited_str[len]);
		find_node(stack, data);
		node = create_node(data);
		st_push(stack, node);
	}
	ft_free(splited_str);
}

void	case_only_atoi(t_stack *stack, int argc, char **argv)
{
	t_node	*node;
	int		data;

	while (argc >= 2)
	{
		--argc;
		if (argv[argc][0] == '\0')
			print_error();
		data = push_swap_atoi(argv[argc]);
		find_node(stack, data);
		node = create_node(data);
		st_push(stack, node);
	}
}

void	setting(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
		case_split(stack, argv);
	else
		case_only_atoi(stack, argc, argv);
}
