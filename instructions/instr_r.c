#include "push_swap.h"
#include "libft.h"

void ra(t_list **stack_a)
{
    if (!stack_a || ft_lstsize(*stack_a) < 2)
        return;
    rotate(stack_a);
    ft_putendl_fd("ra", 1);
}

void rb(t_list **stack_b)
{
    if (!stack_b || ft_lstsize(*stack_b) < 2)
        return;
    rotate(stack_b);
    ft_putendl_fd("rb", 1);
}

void rr(t_list **stack_a, t_list **stack_b)
{
    if ((!stack_a || ft_lstsize(*stack_a) < 2) && (!stack_b || ft_lstsize(*stack_b) < 2))
        return;
    if (stack_a && ft_lstsize(*stack_a) >= 2)
        rotate(stack_a);
    if (stack_b && ft_lstsize(*stack_b) >= 2)
        rotate(stack_b);
    ft_putendl_fd("rr", 1);
}
