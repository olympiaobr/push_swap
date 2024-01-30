#include "push_swap.h"
#include "libft.h"

int main(int argc, char **argv)
{
    char **args;
    t_list *stack_a = NULL, *stack_b = NULL;

    if (!validate_args(argc, argv) || !store_args(argc, argv, &args))
        ft_error("Error\n");
    stack_a = init_stack(stack_a, args);
    ft_free_array(args); 

    // Check for duplicates
    if (!check_int_dup(args, argc - 1))
    {
        clear_stack(&stack_a);
        ft_error("Error\n");
    }
    // Index the stack
    assign_indexes(&stack_a);
    // Check if the stack is already sorted
    if (is_stack_sorted(stack_a))
    {
        clear_stack(&stack_a);
        return (0);
    }
    // Sorting decision
    push_swap(&stack_a, &stack_b);
    // Free resources
    clear_stack(&stack_a);
    clear_stack(&stack_b);

    return (0);
}
/* #include "push_swap.h"
#include "libft.h"
#include <limits.h>

int main(int argc, char **argv) {
    t_list *stack_a;
    t_list *stack_b;
    char **args;

    if (!validate_args(argc, argv, &args))
        return (1);

    stack_a = init_stack(NULL, args);
    stack_b = NULL;

    if (!is_stack_sorted(stack_a)) {
        sort_stack(&stack_a, &stack_b);
    }

    clear_stack(&stack_a);
    clear_stack(&stack_b);
    ft_free_array(args);
    return (0);
}


OR

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    char **args;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);
    if (!store_args(argc, argv, &args))
        ft_error("Error\n");
    if (!check_int_dup(args, ft_count_args(args)))
    {
        ft_free_array(args);
        ft_error("Error\n");
    }
    stack_a = init_stack(stack_a, args);
    assign_indexes(&stack_a);
    if (!is_stack_sorted(stack_a))
        sort_stack(&stack_a, &stack_b);
    clear_stack(&stack_a);
    clear_stack(&stack_b);
    ft_free_array(args);
    return (0);
}
*/
void push_swap(t_list **stack_a, t_list **stack_b) {
    int size = calculate_size(*stack_a);

    if (size <= 3) {
        combined_sort_small(stack_a, stack_b);
    } else if (size > 3 && size <= 5) {
        custom_push_and_sort(stack_a, stack_b);
    } else {
        improved_radix_sort(stack_a, stack_b);
    }
}

...

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	all;
	int		*num;
	int		*index;
	char	**bin;

	if (argc == 1)
		exit(true);
	argc--;
	argv++;
	num = malloc(sizeof(int) * argc);
	if (!num)
		exit(EXIT_FAILURE);
	validate_args(argc, argv);
	transform_args(argc, argv, num);
	check_duplicates(argc, num);
	if (array_is_sorted(argc, num))
		exit(true);
	index = link_index(argc, num);
	bin = string_bin(argc, index);
	init_struct(&all, argc);
	fill_stack_a(&all, bin, index);
	push_swap(&all, index);
	freeing(&all, num, index, bin);
	return (false);
}

void	init_struct(t_all *all, int argc)
{
	all->a = NULL;
	all->b = NULL;
	all->len = argc;
}

void	fill_stack_a(t_all *all, char **bin, int *index)
{
	int	i;

	if (all->len)
	{
		i = 0;
		all->a = ps_lstnew(bin[i], index[i]);
		while (i < all->len - 1)
		{
			i++;
			ps_lstadd_back(&all->a, ps_lstnew(bin[i], index[i]));
		}
	}
}

void	push_swap(t_all *all, int *index)
{
	if (all->len <= 5)
		short_push_swap(all, index);
	else
		long_push_swap(all);
}
