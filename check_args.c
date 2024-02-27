/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:51:24 by olobresh          #+#    #+#             */
/*   Updated: 2024/01/25 18:51:25 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_args_from_argv(int argc, char **argv, char ***args)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		(*args)[i - 1] = strdup(argv[i]);
		if (!(*args)[i - 1])
		{
			free_arr(*args);
			return (0);
		}
		i++;
	}
	(*args)[i - 1] = NULL;
	return (1);
}

int	store_args(int argc, char **argv, char ***args)
{
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!(*args) || !(**args))
			return (0);
	}
	else
	{
		*args = (char **)malloc(sizeof(char *) * argc);
		if (!(*args))
			return (0);
		if (!init_args_from_argv(argc, argv, args))
			return (0);
	}
	return (1);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (atoi_range(str) == 0)
		return (0);
	return (1);
}

int	atoi_range(char *num)
{
	long long	result;
	int			mult;

	result = 0;
	mult = 1;
	while (*num == ' ' || (*num >= 9 && *num <= 13))
		num++;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			mult = -1;
		num++;
	}
	while (*num >= '0' && *num <= '9')
	{
		result = result * 10 + (*num - '0') * mult;
		if (result < INT_MIN || result > INT_MAX)
			return (0);
		num++;
	}
	return (1);
}

int	check_args(int argc, char **argv, char ***args)
{
	int	i;

	if (argc < 2)
		ft_error(NULL);
	if (argv[1][0] == '\0')
		ft_error("Error\n");
	if (!store_args(argc, argv, args))
		ft_error("Error\n");
	i = 0;
	while ((*args)[i])
	{
		if (!check_int((*args)[i]))
		{
			free_arr(*args);
			ft_error("Error\n");
		}
		i++;
	}
	return (1);
}
