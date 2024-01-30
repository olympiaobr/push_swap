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

t_list  *initialize(t_list  *s, char **elements)
{
    int idx;

    s = create_node(ft_atoi(elements[0]));
    idx = 1;
    while (elements[idx])
	{
        	add_to_stack(s, create_node(ft_atoi(elements[idx++])));
    	}
    return s;
}

void push_swap(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = list_len(*stack_a);
    if (size <= 5)
    {
        small_stack_sort(stack_a, stack_b);
    }
    else
    {
        lsd_rad(stack_a, stack_b);
    }
}

int main(int argc, char **argv)
{
    char **args;
    t_list *stack_a;
    t_list *stack_b;

    args = NULL;
    stack_a = NULL;
    stack_b = NULL;
    if (!validate_args(argc, argv) || !store_args(argc, argv, &args))
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
