/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:51:09 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:51:10 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *create_node(int value)
{
    t_list  *new_node = malloc(sizeof(t_list ));
    if (new_node == NULL)
	{
        	return NULL;
    }
    new_node->content = value;
    new_node->next = NULL;
    return new_node;
}

void add_to_stack(t_list  *s, t_list  *new_element)
{
    t_list *tmp ;

    tmp = s;
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

int	ft_lstsize(t_list *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}

void	ft_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(0);
}
