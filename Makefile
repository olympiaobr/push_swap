NAME	= push_swap

HEADERS = push_swap.h libft/libft.h

LIBFT = libft/

INCLUDE = -L ./libft -lft

SRCS	= ./srcs/
	  ./srcs/
	  ./srcs/
	  ./srcs/
	  ./srcs/
	  ./srcs/
	  ./srcs/

OBJS = $(SRCS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

RM	= rm -f

AR	= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -g $(OBJS) -o $(NAME) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean

re:	fclean all

.PHONY: all clean fclean re
