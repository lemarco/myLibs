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

NAME = output.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES =			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\


OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[37;1;42moutput library compiling...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(FILES)
	@echo "\033[37;1;42moutput library objects compiling...\033[0m"
	@gcc $(CFLAGS) $(FILES)

clean:
	@echo "\033[37;1;41moutput library object files deleting...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[37;1;41moutput library library deleting...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re