# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/12 15:08:39 by rkaras        #+#    #+#                  #
#    Updated: 2025/05/16 14:48:48 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Name of the output program
NAME = now_talking

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11

# Source and object files
SRCS = main.cpp \
		Fixed.cpp
		
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Link the object files into the final binary
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re