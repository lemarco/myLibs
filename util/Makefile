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

NAME = util.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES =	ft_atoi.c ft_error.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
		ft_isdigit.c ft_isprint.c ft_itoa.c get_next_line.c\

OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[37;1;42mutil library compiling...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(FILES)
	@echo "\033[37;1;42mutil library objects compiling...\033[0m"
	@gcc $(CFLAGS) $(FILES) -I../output -I../memlib

clean:
	@echo "\033[37;1;41mutil library object files deleting...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[37;1;41mutil library library deleting...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
