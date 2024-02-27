/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:57 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/26 14:50:54 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

//Checks
int		check_args(int argc, char **argv, char ***args);
int		store_args(int argc, char **argv, char ***args);
int		init_args_from_argv(int argc, char **argv, char ***args);
int		check_int(char *str);
int		atoi_range(char *num);

// Instructions
void	swap(t_list **stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	sb(t_list **first_node_b);
void	sa(t_list **first_node_a);
void	ss(t_list **first_node_a, t_list **first_node_b);

// Indexing
t_list	*find_next_smallest(t_list **stack);
void	assign_indexes(t_list **stack);

//Algorithms
void	ft_sort_three(t_list **stack_a);
void	ft_sort_four(t_list **stack_a, t_list **stack_b);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_sort_simple(t_list **stack_a, t_list **stack_b);
int		max_index_find(t_list *lst);
int		max_bits_calc(t_list *lst);
void	lsd_raaadix(t_list **stack_a, t_list **stack_b);

// Utils
int		find_position(t_list *stack, int value);
int		list_len(t_list *stack);
int		min_val(t_list *stack);
int		max_val(t_list *stack);
int		list_order(t_list *stack);
void	ft_error(char *err);
t_list	*create_node(int value);
void	add_to_stack(t_list **s, t_list *new_element);
int		find_double(t_list *s);
void	clear_stack(t_list **s);
t_list	*initialize(char **args);
int		ft_lstsize(t_list *lst);
void	free_arr(char **array);
void	cleanup_and_exit(
			char **args, t_list **stack_a, t_list **stack_b, int exit_code);

//Main
void	push_swap(t_list **stack_a, t_list **stack_b);
int		main(int argc, char **argv);

#endif
