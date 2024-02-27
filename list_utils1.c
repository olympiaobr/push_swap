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

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->content = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_stack(t_list **s, t_list *new_element)
{
	t_list	*tmp;

	if (*s == NULL)
	{
		*s = new_element; 
	}
	else
	{
		tmp = *s;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new_element; 
	}
}

int	find_double(t_list *s)
{
	t_list	*current;
	t_list	*to_compare;

	current = s;
	while (current != NULL && current->next != NULL)
	{
		to_compare = current->next;
		while (to_compare != NULL)
		{
			if (to_compare->content == current->content)
			{
				return (0);
			}
			to_compare = to_compare->next;
		}
		current = current->next;
	}
	return (1); 
}

void	clear_stack(t_list **s)
{
	t_list	*curr;
	t_list	*next_el;

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
