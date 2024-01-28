#include "push_swap.h"
#include "libft.h"
#include <limits.h>

// Helper function to split and store arguments
int store_args(int argc, char **argv, char ***args)
{
    int i;

    i = 0;
    if (argc == 2)
        {
            *args = ft_split(argv[1], ' ');
        }
    else
        {
            *args = malloc(sizeof(char *) * argc);
            if (!(*args)) return (0);
            while (++i < argc)
                (*args)[i - 1] = ft_strdup(argv[i]);
            (*args)[i - 1] = NULL;
        }
        return (*args != NULL);
}

// Combined function to check if string is a valid integer and for duplicates
int check_int_dup(char **args, int count)
{
    long long num;
    int *nums;
    int i;
    int j;

    nums = malloc(sizeof(int) * count);
    if (!nums)
        return (0);

    i = 0;
    while (i < count)
    {
        num = ft_atoi(args[i]);
        if (num < INT_MIN || num > INT_MAX)
        {
            free(nums);
            return (0);
        }
        nums[i] = (int)num;
        j = 0;
        while (j < i)
        {
            if (nums[j] == nums[i])
            {
                free(nums);
                return (0);
            }
            j++;
        }
        i++;
    }
    free(nums);
    return (1);
}

void ft_free_array(char **array)
{
    int i;

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

int validate_args(int argc, char **argv)
{
    char **args;
    int valid = 1;

    if (!store_args(argc, argv, &args))
        ft_error("Memory error");
    int count = 0;
    while (args[count]) count++;

    if (!is_valid_integer_and_no_duplicates(args, count))
        ft_error("Invalid input");

    ft_free_array(args);
    return (valid);
}



/*bool	args_are_integers(char **args_list)
{
	while (*args_list)
	{
		if (ft_atol(*args_list) > INT_MAX || ft_atol(*args_list) < INT_MIN)
			return (false);
		args_list++;
	}
	return (true);
}
*/
