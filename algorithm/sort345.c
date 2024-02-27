/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort235.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:54:07 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/22 15:05:23 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three(t_list **stack_a)
{
	int	max_idx;
	int	max_pos;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || list_order(*stack_a))
		return ;
	max_idx = max_val(*stack_a);
	max_pos = find_position(*stack_a, max_idx);
	if (max_pos == 0)
		ra(stack_a);
	else if (max_pos == 1)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_index;
	int	pos_min;

	if (!stack_a || !(*stack_a))
		return ;
	min_index = min_val(*stack_a);
	while ((*stack_a)->content != min_index)
	{
		pos_min = find_position(*stack_a, min_index);
		if (pos_min >= 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_b, stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_index;

	if (!stack_a || !(*stack_a))
		return ;
	min_index = min_val(*stack_a);
	while ((*stack_a)->content != min_index)
		ra(stack_a);
	pb(stack_a, stack_b);
	min_index = min_val(*stack_a);
	while ((*stack_a)->content != min_index)
		ra(stack_a);
	pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	if (*stack_a && (*stack_a)->next 
		&& (*stack_a)->content > (*stack_a)->next->content) 
	{
		sa(stack_a);
	}
}

void	ft_sort_simple(t_list **stack_a, t_list **stack_b)
{
	int	length;

	if (!stack_a || !(*stack_a))
		return ;
	length = list_len(*stack_a);
	if (length == 2 && (*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
	else if (length == 3)
		ft_sort_three(stack_a);
	else if (length == 4)
		ft_sort_four(stack_a, stack_b);
	else if (length == 5)
		ft_sort_five(stack_a, stack_b);
}
