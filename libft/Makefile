# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 16:25:10 by cmetee-b          #+#    #+#              #
#    Updated: 2024/11/28 16:25:30 by cmetee-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#les_variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#les_fichiers
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
       ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
       ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	   ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o)

#regles
%.o: %.c
	$(CC) $(CFLAGS) -I libft.h -c $< -o $@

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Compilation reussie!"

all: $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "Compilation avec Bonus reussie!"

clean:
	@/bin/rm -rf $(OBJS) $(BONUS_OBJS)
	@echo "Nettoyage des fichiers objects!"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "Netoyage complet!"

re: fclean all

.PHONY: all clean fclean re
