# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2024/10/10 16:44:13 by rkaras        #+#    #+#                  #
#    Updated: 2025/04/07 15:41:34 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++11

SOURCE = megaphone.cpp

OBJECTS = $(SOURCE:.cpp=.o)

all: $(NAME)

$(OBJECTS): $(SOURCE)
		@$(CC) $(CPPFLAGS) -c $(SOURCE) -o $(OBJECTS)

$(NAME): $(OBJECTS)
		@$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re