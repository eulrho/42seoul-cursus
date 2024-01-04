/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erho <erho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:27:20 by erho              #+#    #+#             */
/*   Updated: 2024/01/01 19:12:25 by erho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PASS 0
# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define RRA 5
# define RRB 6
# define PA 7
# define PB 8
# define SS 9
# define RR 10
# define RRR 11

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/includes/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	unsigned int	cost;
	unsigned int	idx;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	unsigned int	size;
}	t_stack;

typedef struct s_check
{
	unsigned int	mid_a;
	unsigned int	mid_b;
	int				is_mid_a_up;
	int				is_mid_b_up;
}	t_check;

// stack
t_stack			*stack_init(void);
t_node			*create_node(int data);
void			setting(t_stack *stack, int size, char **argv);

// moves
void			st_push(t_stack *stack, t_node *node);
void			st_swap(t_stack *stack);
void			st_rotate(t_stack *stack, t_node *target, t_node *dest);

// commands
int				pa(t_stack *a, t_stack *b);
int				pb(t_stack *a, t_stack *b);
int				sa(t_stack *a);
int				sb(t_stack *b);
int				ra(t_stack *a);
int				rb(t_stack *b);
int				rra(t_stack *a);
int				rrb(t_stack *b);

// print
void			print_error(void);
void			print_command(int command_no);

// length
size_t			ft_two_dim_len(char **str);

// sort
int				is_sorted(t_stack *stack);
void			sort_three(t_stack *stack);
void			set_idx(t_stack *stack);
void			set_target_in_a(t_stack *current, t_stack *dest);
void			set_target_in_b(t_stack *current, t_stack *dest);
void			move_a_to_b(t_stack *a, t_stack *b);
void			move_b_to_a(t_stack *a, t_stack *b);
void			move_top(t_stack *a, t_node *first,
					t_stack *b, t_node *second);
t_check			set_check(t_stack *a, t_node *first,
					t_stack *b, t_node *second);
void			move_a_and_b(t_stack *a, t_node *first,
					t_stack *b, t_node *second);
void			set_cost_a(t_stack *a, t_stack *b);
void			set_cost_b(t_stack *a, t_stack *b);

// utils
void			ft_free(char **res);
int				push_swap_atoi(const char *str);

// find
void			find_node(t_stack *stack, int data);
unsigned int	find_max(unsigned int a, unsigned int b);
t_node			*find_min_cost_node(t_stack *stack);
t_node			*find_max_node(t_stack *stack);
t_node			*find_min_node(t_stack *stack);

#endif
