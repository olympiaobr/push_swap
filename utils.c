/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:19:37 by olobresh          #+#    #+#             */
/*   Updated: 2024/02/22 15:19:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list *stack, int value)
{
	int		position;
	t_list	*current;

	position = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->content == value)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

void	free_arr(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	cleanup_and_exit(char **args, 
		t_list **stack_a, t_list **stack_b, int exit_code)
{
	free_arr(args);
	clear_stack(stack_a);
	if (stack_b != NULL)
	{
		clear_stack(stack_b);
	}
	if (exit_code == 1)
	{
		ft_error("Error: Duplicate values found\n");
	}
	exit(exit_code);
}
