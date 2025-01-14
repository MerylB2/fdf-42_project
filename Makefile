# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asiatik <asiatik@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 14:51:14 by cmetee-b          #+#    #+#              #
#    Updated: 2025/01/14 22:39:39 by asiatik          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#les_variables
NAME = fdf
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
MINILIBXTAR = minilibx-linux.tgz
MINILIBXDIR = minilibx-linux
MINILIBX = $(MINILIBXDIR)/libmlx_Linux.a

#FLAGS
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lX11 -lXext -lm 

#les_fichiers
SRCS = fdf.c map_reader.c fdf_utils.c draw.c \

OBJS = $(SRCS:.c=.o)

# BONUS_OBJS = $(BONUS:.c=.o)

#RULES

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS)
	@echo "Compilation reussie!"
	
$(LIBFT):
	make -C $(LIBFTDIR)

$(MINILIBX):
	tar -xzvf $(MINILIBXTAR)
	make -C $(MINILIBXDIR)

all: $(NAME)

# bonus: $(OBJS) $(BONUS_OBJS)
# 	@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
# 	@echo "Compilation avec Bonus reussie!"

clean:
	@/bin/rm -rf $(OBJS)
	make clean -C $(LIBFTDIR)
	@if [ -d $(MINILIBXDIR) ]; then make clean -C $(MINILIBXDIR); fi
	@echo "Nettoyage des fichiers objects!"

fclean: clean
	@/bin/rm -rf $(NAME)
	make fclean -C $(LIBFTDIR)
	@/bin/rm -rf $(MINILIBXDIR)
	@echo "Netoyage complet!"

re: fclean all

.PHONY: all clean fclean re
