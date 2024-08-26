NAME		=	FragTrap

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++17
INCLUDES	=	-I include

_HEADER		=	ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
HEADER		=	$(addprefix include/, $(_HEADER))
_SRC		=	main.cpp\
				ClapTrap.cpp\
				ScavTrap.cpp\
				FragTrap.cpp
SRC			=	$(addprefix src/, $(_SRC))
OBJ			=	$(SRC:src/%.cpp=bin/%.o)

all: $(NAME)

bin:
	@mkdir -p bin/Fixed

bin/%.o: src/%.cpp $(HEADER) | bin
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re