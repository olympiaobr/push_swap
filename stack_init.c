#include "push_swap.h"
#include "libft.h"

t_list  *init_stack(t_list  *s, char **elements)
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

t_list  *create_node(int value)
{
    t_list  *new_node = malloc(sizeof(t_list ));
    if (new_node == NULL)
	{
        return NULL;
    }
    new_node->nb = value;
    new_node->next = NULL;
    return new_node;
}

void add_to_stack(t_list  *s, t_list  *new_element)
{
    t_list *tmp = s;
    while (tmp->next != NULL)
	{
        tmp = tmp->next;
    }
    tmp->next = new_element;
}

void clear_stack(t_list  **s)
{
    t_list *curr;
    t_list *next_el;

	curr = *s;
    while (curr != NULL)
	{
        next_el = curr->next;
        free(curr);
        curr = next_el;
    }
    *s = NULL;
}
