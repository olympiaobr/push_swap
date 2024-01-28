#include "push_swap.h"
#include "libft.h"

void push_swap(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = calculate_size(*stack_a);
    if (size <= 3)
    {
        combined_sort_small(stack_a, stack_b);
    }
    else if (size <= 5)
    {
        custom_push_and_sort(stack_a, stack_b);
    }
    else
    {
        improved_radix_sort(stack_a, stack_b);
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

    stack_a = init_stack(stack_a, args);
    ft_free_array(args);

    if (!check_int_dup(args, argc - 1))
    {
        clear_stack(&stack_a);
        ft_error("Error\n");
    }

    assign_indexes(&stack_a);
    if (!is_stack_sorted(stack_a))
    {
        push_swap(&stack_a, &stack_b);
    }

    clear_stack(&stack_a);
    clear_stack(&stack_b);
    return (0);
}
