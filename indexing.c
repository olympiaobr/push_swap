#include "push_swap.h"
#include "libft.h"

void assign_indexes(t_list  **stack)
{
    int idx = 0;
    t_list  *current;

    while ((current = find_next_smallest(stack, idx)) != NULL)
    {
        current->index = idx;
        idx++;
    }
}

static t_stack *find_next_smallest(t_list  **stack, int current_idx)
{
    t_list  *temp = *stack;
    t_list  *smallest = NULL;

    while (temp)
    {
        if (temp->index == -1 && (!smallest || temp->nb < smallest->nb))
            smallest = temp;
        temp = temp->next;
    }
    return smallest;
}
