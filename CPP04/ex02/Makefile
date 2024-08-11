NAME     = abstract

SRCS     = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
HDRS     = Animal.hpp Dog.hpp Cat.hpp Brain.hpp
OBJS     = $(SRCS:.cpp=.o)
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	@$(CXX) $(OBJS) -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean format re
