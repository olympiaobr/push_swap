t_stack *initialize_stack(char **array)
{
    t_stack *stack;
    int     i;

    if (!array || !*array)
        return (NULL);
    stack = NULL;
    i = 0;
    while (array[i])
    {
        t_stack *new_node = create_node(ft_atoi(array[i]));
        if (!new_node)
        {
            // Handle memory allocation failure
            clear_stack(&stack);
            return (NULL);
        }
        append_node(&stack, new_node);
        i++;
    }
    return (stack);
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*n_node;

	n_node = (t_stack *) malloc(sizeof(*n_node));
	if (!n_node)
		return (NULL);
	n_node->value = value;
	n_node->index = -1;
	n_node->next = NULL;
	return (n_node);
}
