#include "push_swap.h"
#include "libft.h"

void pa(t_list **stack_a, t_list **stack_b)
{
    if (!stack_b || !(*stack_b))
        return;
    push(stack_b, stack_a);
    ft_putendl_fd("pa", 1);
}

void pb(t_list **stack_a, t_list **stack_b)
{
    if (!stack_a || !(*stack_a))
        return;
    push(stack_a, stack_b);
    ft_putendl_fd("pb", 1);
}
