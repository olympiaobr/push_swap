/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:36:42 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/29 10:36:45 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize(char **args)
{
	t_list	*stack;
	int		i;
	int		value;
	t_list	*new_node;

	stack = NULL;
	i = 0;
	while (args[i])
	{
		value = atoi(args[i]);
		new_node = create_node(value);
		add_to_stack(&stack, new_node);
		i++;
	}
	return (stack);
}

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = list_len(*stack_a);
	if (size <= 5)
	{
		ft_sort_simple(stack_a, stack_b);
	}
	else
	{
		lsd_raaadix(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv, &args)) 
	{
		return (1);
	}
	stack_a = initialize(args);
	if (!find_double(stack_a)) 
	{
		cleanup_and_exit(args, &stack_a, NULL, 1);
	}
	assign_indexes(&stack_a);
	if (list_order(stack_a)) 
	{
		cleanup_and_exit(args, &stack_a, &stack_b, 0);
	}
	push_swap(&stack_a, &stack_b);
	cleanup_and_exit(args, &stack_a, &stack_b, 0);
}
/*
int main(int argc, char **argv) 
{

    char **args;
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;
    int success;

    success = 1

    if (check_args(argc, argv, &args)) 
    {
        stack_a = initialize(args);
        if (stack_a && find_double(stack_a)) 
        {
            assign_indexes(&stack_a);
            if (!list_order(stack_a)) 
            {
                push_swap(&stack_a, &stack_b);
                success = 0; 
            }
        } 
        else 
        {
            ft_error("Error: Duplicate values found\n");
            success = 1;
        }
    } 
    else 
        success = 1;
    free_arr(args);
    clear_stack(&stack_a);
    if (stack_b) 
        clear_stack(&stack_b);
    return (success);
}
int main(int argc, char **argv)
{
    char **args;
    t_list *stack_a;
    t_list *stack_b;

    args = NULL;
    stack_a = NULL;
    stack_b = NULL;
    if (!check_args(argc, argv) || !store_args(argc, argv, &args))
        ft_error("Error\n");

    stack_a = initialize(stack_a, args);
    free_arr(args);

    if (!check_int_dup(args, argc - 1))
    {
        clear_stack(&stack_a);
        ft_error("Error\n");
    }

    assign_indexes(&stack_a);
    if (!list_order(stack_a))
    {
        push_swap(&stack_a, &stack_b);
    }

    clear_stack(&stack_a);
    clear_stack(&stack_b);
    return (0);
}
int main(int argc, char **argv) {
    char **array;
    t_list *stack_a = NULL;
    t_list *stack_b = NULL;

    // Assume valid_args not only validates but also parses argv into array
    if (!valid_args(argc, argv, &array)) {
        // Handle invalid arguments case
        ft_error("Error\n", 1);
    }

    stack_a = initialize_stack(array);
    if (!find_duplicate(stack_a)) {

        free_parsed_args(array); // Placeholder for actual function
        clear_stack(&stack_a);
        ft_error("Error\n", 1);
    }


    index_stack(&stack_a);
    if (is_sorted(stack_a)) {
        free_parsed_args(array); // Placeholder for actual function
        clear_stack(&stack_a);
        exit(0);
    }


    sort(&stack_a, &stack_b);

    // Clean up
    free_parsed_args(array); // Placeholder for actual function
    clear_stack(&stack_a);
    clear_stack(&stack_b);
}
*/
