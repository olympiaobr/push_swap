/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:46:33 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/26 13:18:11 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **first_node_a)
{
	swap(first_node_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **first_node_b)
{
	swap(first_node_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list **first_node_a, t_list **first_node_b)
{
	swap(first_node_a);
	swap(first_node_b);
	ft_putendl_fd("ss", 1);
}
/*
or
void sa(t_list **first_node_a)
{
    if (first_node_a && ft_lstsize(*first_node_a) > 1)
    {
        swap(first_node_a);
        write(1, "sa\n", 3);
    }
}

void sb(t_list **first_node_b)
{
    if (first_node_b && ft_lstsize(*first_node_b) > 1)
    {
        swap(first_node_b);
        write(1, "sb\n", 3);
    }
}

void ss(t_list **first_node_a, t_list **first_node_b)
{
    if ((first_node_a && ft_lstsize(*first_node_a) > 1) 
    && (first_node_b && ft_lstsize(*first_node_b) > 1))
    {
        swap(first_node_a);
        swap(first_node_b);
        write(1, "ss\n", 3);
    }
}

 void ss(t_list **stack_a, t_list **stack_b)
{
    if (ft_lstsize(*stack_a) >= 2 
    && ft_lstsize(*stack_b) >= 2)
    {
        swap(stack_a);
        swap(stack_b);
        ft_putendl_fd("ss", 1);
    }
}
*/
