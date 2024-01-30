/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:50:57 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:50:59 by olobresh         ###   ########.fr       */
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
    int content;
    int index;
    struct s_list *next;
} t_list;

//Checks
int validate_args(int argc, char **argv);
int store_args(int argc, char **argv, char ***args);
void free_arr(char **array);
int check_int_dup(char **args, int count);

// Instructions
void swap(t_list **stack);
void push(t_list **src, t_list **dest);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
void sa(t_list **first_node_a);
void sb(t_list **first_node_b);
void ss(t_list **first_node_a, t_list **first_node_b);


// Indexing
t_list *find_next_smallest(t_list  **stack);
void		assign_indexes(t_list  **stack);

//Algorithms
void sort_three(t_list **stack_a);
void sort_five(t_list **stack_a, t_list **stack_b);
void small_stack_sort(t_list **stack_a, t_list **stack_b);
void	lsd_rad(t_list  **stack_a, t_list  **stack_b);;
void execute_bitwise_sorting(t_list **stack_a, t_list **stack_b, int bit, int size);
int	custom_max_bits(t_list  *stack);

// Utils
int		list_len(t_list *stack);
int		min_val(t_list *stack);
int		max_val(t_list *stack);
int		list_order(t_list *stack);
void		ft_error(char *err);
t_list  	*create_node(int value);
void 		add_to_stack(t_list  *s, t_list  *new_element);
void		clear_stack(t_list  **s);
t_list  *initialize(t_list  *s, char **elements);
int	ft_lstsize(t_list *lst);

//Main
void push_swap(t_list **stack_a, t_list **stack_b);
int main(int argc, char **argv);

#endif
