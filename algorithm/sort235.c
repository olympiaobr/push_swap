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

void sort_three(t_list **stack_a)
{
    if (list_order(*stack_a)) // Check if already sorted
        return;

    int first = (*stack_a)->content;
    int second = (*stack_a)->next->content;
    int third = (*stack_a)->next->next->content;

    if (first > second && first < third) // Case 1
        sa(stack_a);
    else if (first > third && second > third) // Case 2
        rra(stack_a);
    else if (first > second && second > first) // Case 3
    {
        sa(stack_a);
        ra(stack_a);
    }
    else if (first < second && first > third) // Case 4
        ra(stack_a);
    // Other cases mean the stack is already sorted
}

void sort_five(t_list **stack_a, t_list **stack_b)
{
    if (list_order(*stack_a)) // Check if already sorted
        return;

    while (list_len(*stack_a) > 3)
    {
        if ((*stack_a)->content == min_val(*stack_a) ||
            (*stack_a)->content == max_val(*stack_a))
            pb(stack_a, stack_b); // Push min or max to stack_b
        else
            ra(stack_a); // Rotate stack_a
    }

    sort_three(stack_a); // Sort the three elements in stack_a

    while (list_len(*stack_b) > 0)
    {
        pa(stack_b, stack_a); // Push back to stack_a
        if (!list_order(*stack_a))
            ra(stack_a); // Rotate stack_a if not sorted
    }
}

void small_stack_sort(t_list **stack_a, t_list **stack_b)
{
    int size = list_len(*stack_a);
    if (size == 2 && (*stack_a)->content > (*stack_a)->next->content)
        sa(stack_a); // Just swap for two elements
    else if (size == 3)
        sort_three(stack_a);
    else if (size == 4 || size == 5)
        sort_five(stack_a, stack_b);
}
