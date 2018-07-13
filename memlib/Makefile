#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 12:28:11 by ihoienko          #+#    #+#              #
#    Updated: 2017/10/27 12:28:12 by ihoienko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = memlib.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES = ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
		ft_memdel.c ft_memmove.c ft_memset.c\

OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[37;1;42mmemory library compiling...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(FILES)
	@echo "\033[37;1;42mmemory library objects compiling...\033[0m"
	@gcc $(CFLAGS) $(FILES)

clean:
	@echo "\033[37;1;41mmemory library object files deleting...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[37;1;41mmemory library library deleting...\033[0m"
	@rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean all re