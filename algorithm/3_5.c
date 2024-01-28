#include "../push_swap.h"

void combined_sort_small(t_list  **stack_a, t_list  **stack_b)
{
    int size;

    size = calculate_size(*stack_a);
    if (size == 2 && !is_stack_sorted(*stack_a))
        sa(stack_a);
    else if (size == 3)
        detailed_sort_three(stack_a, stack_b);
}

void detailed_sort_three(t_list  **stack_a, t_list  **stack_b)
{
    int top, middle, bottom;

    top = (*stack_a)->content;
    middle = (*stack_a)->next->content;
    bottom = (*stack_a)->next->next->content;

    if (top > middle && middle < bottom)
    {
        if (top < bottom)
            sa(stack_a);
        else
            ra(stack_a);
    }
    else if (top > middle && middle > bottom)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (top < middle && middle > bottom)
    {
        if (top < bottom)
            rra(stack_a);
        else
        {
            sa(stack_a);
            ra(stack_a);
        }
    }
}

void custom_push_and_sort(t_list  **stack_a, t_list  **stack_b)
{
    while (calculate_size(*stack_a) > 3)
    {
        if (is_min_or_max(*stack_a))
            pb(stack_a, stack_b);
        else
            ra(stack_a);
    }
    combined_sort_small(stack_a, stack_b);
    while (calculate_size(*stack_b) > 0)
        pa(stack_b, stack_a);
}

bool is_min_or_max(t_list  *stack)
{
    int min, max;

    min = find_min(stack);
    max = find_max(stack);
    return (stack->content == min || stack->content == max);
}
