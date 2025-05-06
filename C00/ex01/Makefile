# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/14 12:29:46 by rkaras        #+#    #+#                  #
#    Updated: 2025/04/27 13:59:48 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++11

SOURCE = main.cpp \
		PhoneBook.cpp \
		Contact.cpp \

OBJECTS = $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CC) $(CPPFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re