# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/06 13:49:09 by rkaras        #+#    #+#                  #
#    Updated: 2025/05/06 15:51:13 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = zombieHorde

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Source and object files
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Linking
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
