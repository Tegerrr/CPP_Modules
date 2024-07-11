NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

%.o:%.cpp
		c++ $(FLAGS) -c $< -o $@

all: $(NAME)
$(NAME):$(OBJ)
		c++ $(FLAGS) $(OBJ) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re