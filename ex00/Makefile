CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17

NAME := type
SRC = main.cpp ScalarConvert.cpp

OBJ_DIR := obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
fclean:	clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re