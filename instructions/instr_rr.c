/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:46:54 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:46:55 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rra(t_list **stack_a)
{
    if (stack_a && ft_lstsize(*stack_a) > 1)
    {
        reverse_rotate(stack_a);
        ft_putendl_fd("rra", 1);
    }
}

void rrb(t_list **stack_b)
{
    if (stack_b && ft_lstsize(*stack_b) > 1)
    {
        reverse_rotate(stack_b);
        ft_putendl_fd("rrb", 1);
    }
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    if ((stack_a && ft_lstsize(*stack_a) > 1) && (stack_b && ft_lstsize(*stack_b) > 1))
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        ft_putstr_fd("rrr\n", 1);
    }
}
