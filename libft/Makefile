# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarrio <abarrio@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 14:01:21 by abarrio           #+#    #+#              #
#    Updated: 2026/02/14 14:16:06 by abarrio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 VARIABLES                                    #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Directories
LIBFT_DIR	= srcs/libft
PRINTF_DIR	= srcs/ft_printf
GNL_DIR		= srcs/get_next_line
INC_DIR		= includes

# **************************************************************************** #
#                              LIBFT SOURCES                                   #
# **************************************************************************** #

# Part 1 - Libc functions
LIBFT_SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			  ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			  ft_atoi.c ft_calloc.c ft_strdup.c

# Part 2 - Additional functions
LIBFT_SRCS	+= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			   ft_itoa.c ft_strmapi.c ft_striteri.c \
			   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Bonus - Linked lists
LIBFT_SRCS	+= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			   ft_lstmap.c

# **************************************************************************** #
#                             FT_PRINTF SOURCES                                #
# **************************************************************************** #

PRINTF_SRCS	= ft_printf.c ft_print_char.c ft_print_str.c ft_print_ptr.c \
			  ft_print_nbr.c ft_print_unbr.c ft_print_hex.c \
			  ft_putchar_count.c ft_putnbr_base_count.c ft_putstr_count.c

# **************************************************************************** #
#                           GET_NEXT_LINE SOURCES                              #
# **************************************************************************** #

GNL_SRCS	= get_next_line.c get_next_line_utils.c

# **************************************************************************** #
#                                  OBJECTS                                     #
# **************************************************************************** #

LIBFT_OBJS		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_SRCS:.c=.o))
PRINTF_OBJS		= $(addprefix $(PRINTF_DIR)/, $(PRINTF_SRCS:.c=.o))
GNL_OBJS		= $(addprefix $(GNL_DIR)/, $(GNL_SRCS:.c=.o))

OBJS			= $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Compile libft sources
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile ft_printf sources
$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compile get_next_line sources
$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(LIBFT_BONUS_OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re