# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmascaro <nmascaro@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 09:31:26 by nmascaro          #+#    #+#              #
#    Updated: 2025/06/16 13:40:18 by nmascaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = algorithm_operations.c cost_calculation.c input_validation.c main.c more_algorithm_operations.c push_operations.c push_swap.c reverse_rotate_operations.c rotate_operations.c sort_small_stack.c sort_three_nodes.c stack_analysis.c stack_cleaning.c stack_initializing.c stack_utils.c swap_operations.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
