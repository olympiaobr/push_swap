/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:52:04 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:52:05 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_next_smallest(t_list **stack)
{
	t_list	*temp;
	t_list	*smallest;

	temp = *stack;
	smallest = NULL;
	while (temp)
	{
		if (temp->index == -1 && (!smallest 
				|| temp->content < smallest->content))
			smallest = temp;
		temp = temp->next;
	}
	return (smallest);
}

void	assign_indexes(t_list **stack)
{
	int		idx;
	t_list	*current;

	idx = 0;
	current = find_next_smallest(stack);
	while (current != NULL)
	{
		current->index = idx;
		idx++;
		current = find_next_smallest(stack);
	}
}
