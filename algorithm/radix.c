#include "../push_swap.h"

void improved_radix_sort(t_list  **stack_a, t_list  **stack_b)
{
    int max_bits;
    int bit;

    max_bits = custom_max_bits(*stack_a);
    bit = 0;
    while (bit < max_bits)
    {
        execute_bitwise_sorting(stack_a, stack_b, bit);
        bit++;
    }
}

void execute_bitwise_sorting(t_list  **stack_a, t_list  **stack_b, int bit)
{
    int i;
    int size;

    size = calculate_size(*stack_a);
    i = 0;
    while (i < size)
    {
        if (((*stack_a)->index >> bit) & 1)
		{
            ra(stack_a);
            pb(stack_a, stack_b);
		}
		//else ra(stack_a);//
        i++;
    }
    while (calculate_size(*stack_b) > 0)
        pa(stack_b, stack_a);
}

int custom_max_bits(t_list  *stack)
{
    int max_index;
    int count;

    max_index = 0;
    count = 0;
    while (stack)
    {
        if (stack->index > max_index)
            max_index = stack->index;
        stack = stack->next;
    }
    while (max_index >> count)
        count++;
    return count;
}
