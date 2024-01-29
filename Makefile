# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 18:50:30 by olobresh          #+#    #+#              #
#    Updated: 2024/01/25 18:50:33 by olobresh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT = libft/

INCLUDE = -L ./libft -lft

SRCS	= ./check_args.c \
	  ./indexing.c \
	  ./list_utils1.c \
	  ./list_utils2.c \
	  ./push_swap.c \
	  ./algorithm/radix.c \
	  ./algorithm/sort235.c \
	  ./instructions/instr.c \
	  ./instructions/instr_p.c \
	  ./instructions/instr_r.c \
	  ./instructions/instr_rr.c \
	  ./instructions/instr_s.c

OBJS = $(SRCS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

AR	= ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -g $(OBJS) $(INCLUDE) -o $(NAME)

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
