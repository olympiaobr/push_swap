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

// Instructions
void swap(t_list **stack);
void push(t_list **src, t_list **dest);
void rotate(t_list **stack);
void reverse_rotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

// Util functions
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_list **stack);
int		get_distance(t_list **stack, int index);
void	make_top(t_list **stack, int distance);
void	free_stack(t_list **stack);
void	ft_free(char **str);

// Utils
int		calculate_size(t_list **stack);
int		min_value(t_list **stack);
int		max_value(t_list **stack);
int		is_stack_sorted(t_list **stack);
void	ft_error(char *err)

// Indexing
void	assign_indexes(t_list **stack);
static t_list	*find_next_smallest(t_list **stack, int current_idx);

// Sorting





#endif
