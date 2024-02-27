/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:51:36 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:51:38 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_list *stack)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	min_val(t_list *stack)
{
	int		min;
	t_list	*temp;

	if (!stack)
		return (INT_MAX);
	temp = stack;
	min = temp->content;
	while (temp != NULL)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	max_val(t_list *stack)
{
	int		max;
	t_list	*temp;

	if (!stack)
		return (INT_MIN);
	temp = stack;
	max = temp->content;
	while (temp != NULL)
	{
		if (temp->content > max)
			max = temp->content;
		temp = temp->next;
	}
	return (max);
}

int	list_order(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	if (!temp)
		return (1);
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(0);
}
