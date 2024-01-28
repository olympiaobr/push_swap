#include "push_swap.h"
#include "libft.h"

void swap(t_list **stack)
{
    t_list *first;
    t_list  *second;

    if (!stack || !(*stack) || !((*stack)->next))
		return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push(t_list  **src, t_list  **dest)
{
    t_list  *top_node;

    if (!src || !(*src))
		return;
    top_node = *src;
    *src = (*src)->next;
    top_node->next = *dest;
    *dest = top_node;
}

void rotate(t_list  **stack)
{
    t_list  *first, *last;

    if (!stack || !(*stack) || !((*stack)->next))
		  return;
    first = *stack;
    last = *stack;
    while (last->next)
      last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate(t_list  **stack)
{
    t_list  *prev, *last;

    if (!stack || !(*stack) || !((*stack)->next))
		return;
    prev = NULL;
    last = *stack;
    while (last->next)
	  {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}
