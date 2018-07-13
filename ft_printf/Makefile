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

NAME = printf_library.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES =	ft_printf_pointer.c ft_printf_width_and_print.c ft_printf_main.c\
		ft_printf_help_func.c ft_printf_parsers.c ft_printf_nums.c\
		ft_printf_str.c

OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[37;1;42mprintf library compiling...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(FILES)
	@echo "\033[37;1;42mprintf library objects compiling...\033[0m"
	@gcc $(CFLAGS) $(FILES) -I../output -I../memlib

clean:
	@echo "\033[37;1;41mprintf library object files deleting...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[37;1;41mprintf library library deleting...\033[0m"
	@rm -f $(NAME)

re: fclean all
	
.PHONY: clean fclean all re