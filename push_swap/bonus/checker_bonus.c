/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:23:30 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 15:10:29 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_rr(t_stack *a, t_stack *b, char *command)
{
	if (command[2] == '\n')
	{
		ra(a);
		rb(b);
	}
	else if (command[2] == 'a' && command[3] == '\n')
		rra(a);
	else if (command[2] == 'b' && command[3] == '\n')
		rrb(b);
	else if (command[2] == 'r' && command[3] == '\n')
	{
		rra(a);
		rrb(b);
	}
	else
		print_error();
}

void	run(t_stack *a, t_stack *b, char *command)
{
	if (command[0] == 's' && command[1] == 'a' && command[2] == '\n')
		sa(a);
	else if (command[0] == 's' && command[1] == 'b' && command[2] == '\n')
		sb(b);
	else if (command[0] == 'p' && command[1] == 'a' && command[2] == '\n')
		pa(a, b);
	else if (command[0] == 'p' && command[1] == 'b' && command[2] == '\n')
		pb(a, b);
	else if (command[0] == 'r' && command[1] == 'a' && command[2] == '\n')
		ra(a);
	else if (command[0] == 'r' && command[1] == 'b' && command[2] == '\n')
		rb(b);
	else if (command[0] == 's' && command[1] == 's' && command[2] == '\n')
	{
		sa(a);
		sb(b);
	}
	else if (command[0] == 'r' && command[1] == 'r')
		check_rr(a, b, command);
	else
		print_error();
}

void	input_commands(t_stack *a, t_stack *b, char *command)
{
	while (command != NULL)
	{
		run(a, b, command);
		free(command);
		command = get_next_line(0);
	}
	if (b->size != 0)
		ft_printf("KO\n");
	else if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	if (argc >= 2)
	{
		a = stack_init();
		b = stack_init();
		setting(a, argc, argv);
		command = get_next_line(0);
		if (is_sorted(a) && command == NULL)
			ft_printf("OK\n");
		else if (!is_sorted(a) && command == NULL)
			ft_printf("KO\n");
		else
			input_commands(a, b, command);
		exit(0);
	}
	return (0);
}
