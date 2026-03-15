# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 13:36:48 by abarrio           #+#    #+#              #
#    Updated: 2026/03/15 21:10:59 by abarrio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDES 	= -I. -I./libft/includes -I./includes
RM 			= rm -f

LIBFTDIR 	= libft
LIBFT 		= $(LIBFTDIR)/libft.a

SRCS		= srcs/main.c \
			  srcs/parsing/parse_args.c \
			  srcs/utils/parse_utils.c \
			  srcs/utils/stack_utils.c \
			  srcs/utils/stack_utils2.c \
			  srcs/utils/turk_utils.c \
			  srcs/utils/errors.c \
			  srcs/operations/push.c \
			  srcs/operations/swap.c \
			  srcs/operations/rotate.c \
			  srcs/operations/reverse_rotate.c \
			  srcs/sorting/sort_three.c \
			  srcs/sorting/sort_small.c \
			  srcs/sorting/turk_sort.c \
			  srcs/sorting/turk_costs.c \
			  srcs/sorting/turk_positions.c

OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re