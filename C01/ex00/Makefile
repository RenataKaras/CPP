# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/06 13:49:09 by rkaras        #+#    #+#                  #
#    Updated: 2025/05/06 14:42:49 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++11

SOURCE = main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

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