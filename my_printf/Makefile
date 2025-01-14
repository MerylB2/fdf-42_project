# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 17:41:26 by cmetee-b          #+#    #+#              #
#    Updated: 2024/11/29 18:39:36 by cmetee-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#les_variables
NAME = libftprintf.a
LIBFT = libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

#les_fichiers
SRCS = ft_printf.c ft_utils.c

OBJS = $(SRCS:.c=.o)

#regles
all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@cp $(LIBFT) $(NAME) 
	@ar rcs $@ $(OBJS)
	@echo "COMPILATION DE MY_PRINTF REUSSIE!!!!"

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	@make -C ./libft clean
	@rm -rf $(OBJS)
	@echo "NETTOYAGE DES FICHIERS OBJECTS DE MY_PRINTF!! OK"

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)
	@echo "NETTOYAGE COMPLET DE MY_PRINTF!!! OK"

re: fclean all

.PHONY: all clean fclean re
