# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkaras <rkaras@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2025/05/26 13:40:59 by rkaras        #+#    #+#                  #
#    Updated: 2025/05/27 14:33:05 by rkaras        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Name of the output program
NAME = polymorphism

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -MMD -MP

# Source and object files
SRCS = main.cpp \
		Dog.cpp \
		Cat.cpp \
		AAnimal.cpp \
		WrongCat.cpp \
		WrongAnimal.cpp \
		Brain.cpp
		
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

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
	rm -f $(OBJS) $(DEPS)

# Remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
