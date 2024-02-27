/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:53:29 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/22 15:04:57 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_index_find(t_list *lst)
{
	int		max_idx;
	t_list	*current;

	if (lst == NULL)
		return (-1);
	max_idx = lst->index;
	current = lst;
	while (current != NULL)
	{
		if (current->index > max_idx)
		{
			max_idx = current->index;
		}
		current = current->next;
	}
	return (max_idx);
}

int	max_bits_calc(t_list *lst)
{
	int	max_idx;
	int	bits;

	bits = 0;
	max_idx = max_index_find(lst);
	while (max_idx > 0)
	{
		bits = bits + 1;
		max_idx = max_idx >> 1;
	}
	return (bits);
}

void	lsd_raaadix(t_list **stack_a, t_list **stack_b)
{
	int		bit_level;
	int		processed_elements;
	int		list_size;
	int		max_bits;
	t_list	*current_node;

	bit_level = 0;
	list_size = list_len(*stack_a); 
	max_bits = max_bits_calc(*stack_a);
	while (++bit_level <= max_bits)
	{
		processed_elements = 0;
		while (processed_elements < list_size)
		{
			current_node = *stack_a;
			if (((current_node->index >> (bit_level - 1)) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			processed_elements++;
		}
		while (list_len(*stack_b) > 0)
			pa(stack_a, stack_b);
	}
}
