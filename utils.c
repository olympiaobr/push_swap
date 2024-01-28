#include "push_swap.h"
#include "libft.h"

int calculate_size(t_list *stack)
{
    int count = 0;
    t_list *temp = stack;

    while (temp)
    {
        count++;
        temp = temp->next;
        if (temp == stack) break;
    }
    return count;
}

int min_value(t_list *stack)
{
    int min;
    t_list *temp;

    if (!stack)
        return (INT_MAX);
    temp = stack;
    min = temp->nb;
    while (1)
    {
        if (temp->nb < min)
            min = temp->nb;
        temp = temp->next;
        if (temp == stack)
            break ;
    }
    return (min);
}

int max_value(t_list *stack)
{
    int max;
    t_list *temp;

    if (!stack)
        return (INT_MIN);
    temp = stack;
    max = temp->nb;
    while (1)
    {
        if (temp->nb > max)
            max = temp->nb;
        temp = temp->next;
        if (temp == stack)
            break ;
    }
    return (max);
}

int is_stack_sorted(t_list *stack)
{
    t_list *temp = stack;

    while (temp->next && temp->next != stack)
    {
        if (temp->nb > temp->next->nb)
            return 0;
        temp = temp->next;
    }
    return 1;
}
