/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:54:07 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:54:08 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void combined_sort_small(t_list  **stack_a, t_list  **stack_b)
{
    int size;

    size = list_len(*stack_a);
    if (size == 2 && !list_order(*stack_a))
        sa(stack_a);
    else if (size == 3)
        detailed_sort_three(stack_a, stack_b);
}

void detailed_sort_three(t_list **stack_a, t_list **stack_b)
{
    // Temporarily move the smallest or largest element to stack_b
    if ((*stack_a)->content > (*stack_a)->next->content && 
        (*stack_a)->content > (*stack_a)->next->next->content) {
        pb(stack_a, stack_b); // Push the largest element to stack_b
    } else if ((*stack_a)->content < (*stack_a)->next->content && 
               (*stack_a)->content < (*stack_a)->next->next->content) {
        pb(stack_a, stack_b); // Push the smallest element to stack_b
        sa(stack_a);          // Swap the remaining two elements in stack_a if needed
    }

    // Sort the remaining two elements in stack_a
    if ((*stack_a)->content > (*stack_a)->next->content) {
        sa(stack_a);
    }

    // Push back the element from stack_b to stack_a if stack_b is not empty
    if (list_len(*stack_b) > 0) {
        pa(stack_b, stack_a);
    }

    // Additional check if the pushed back element needs to be rotated to the correct position
    if ((*stack_a)->content > (*stack_a)->next->content) {
        ra(stack_a);
    }
}

void custom_push_and_sort(t_list  **stack_a, t_list  **stack_b)
{
    while (list_len(*stack_a) > 3)
    {
        if (is_min_or_max(*stack_a))
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
    combined_sort_small(stack_a, stack_b);
    while (list_len(*stack_b) > 0)
        pa(stack_b, stack_a);
}

bool is_min_or_max(t_list  *stack)
{
    int min;
    int max;

    min = min_val(stack);
    max = max_val(stack);
    return (stack->content == min || stack->content == max);
}
