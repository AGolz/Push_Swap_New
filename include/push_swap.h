/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaksimo <emaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 10:43:15 by cfiora            #+#    #+#             */
/*   Updated: 2023/09/06 01:20:40 by emaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				sort;
	struct s_stack	*next;
}						t_stack;

typedef struct s_stacks
{
	int				length_a;
	int				length_b;
	int				optimum_a;
	int				optimum_b;
	int				optimum_pl;
	int				tmp_a;
	int				tmp_b;
	int				tmp_pl;
	int				cmd_print;
	int				cmd_cnt;
	t_stack			*a;
	t_stack			*b;
	t_stack			*max_sort;
}						t_stacks;

void		sort_too_elements(t_stacks *satcks);
void		sort_three_elements(t_stacks *satcks);
void		sort_four_elements(t_stacks *satcks);
void		sort_five_elements(t_stacks *satcks);

int			findminimum_value(t_stacks *satcks);
int			node_counter_b_to_a(int a, int b, int place_b);
void		set_index(t_stack *stack);

void		cmd_counter(char *command, int cnt, t_stacks *stacks);

void		principal_node_min(t_stacks *stacks);
t_stack		*principal_nodes_front(t_stack **stack);
t_stack		*principal_nodes_back(t_stack **stack);

int			push_element(t_stack **stk_destination, t_stack **stk_source);
void		push_back(t_stack **stack, t_stack *new);
void		push_front(t_stack **stack, t_stack *new);
t_stack		*push_back_int(t_stack **stack, int value);

int			swap_elements(t_stack **stack);
int			rotate_elements(t_stack **stack);
int			reverse_rotate_elements(t_stack **stack);

void		moving_a_to_b(t_stacks	*satcks);
void		moving_b_to_a(t_stacks	*satcks);
void		moving_node_b_to_a(t_stacks	*satcks);
void		stack_normalization(t_stacks *stacks);

int			distance_node_from_apex(int stack_len, int node_index);
int			get_node_location_index(t_stack *stack, int node_value);
t_stack		*get_maximum_nodes(t_stack *stack);

int			counter_node(t_stack *stack);
t_stack		*create_new_node(int value);
t_stack		*get_last_node(t_stack *stack);
t_stacks	*create_stacks(int argc, char **argv);

int			free_stacks(t_stacks **stacks, int ret_num);
int			stack_set_commandd(t_stacks *stacks, t_stack *tmp_b);
void		copy_optimum_place(t_stacks *stacks);
void		display_error_message(t_stacks **stack, int ret_num);

int			valid_int(int value_i, char *value_c);
int			not_duplicates(t_stack *stack, int value);
int			stack_is_sorted(t_stacks *stacks);
int			sort_stacks_check(t_stacks *stacks);

#endif