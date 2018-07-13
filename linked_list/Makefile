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

NAME = linked_list.a
CFLAGS = -Wall -Werror -Wextra -I. -c
FILES =	ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c\
		ft_lstmap.c

OBJ	= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[37;1;42mLinked list lib compiling...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(FILES)
	@echo "\033[37;1;42mLinked list objects compiling...\033[0m"
	@gcc $(CFLAGS) $(FILES) -I../memlib/

clean:
	@echo "\033[37;1;41mLinked list object files deleting...\033[0m"
	@rm -f $(OBJ)

fclean: clean
	@echo "\033[37;1;41mLinked list library deleting...\033[0m"
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
