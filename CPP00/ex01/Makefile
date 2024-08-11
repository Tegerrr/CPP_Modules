NAME     = phonebook

SRCS     = main.cpp PhoneBook.cpp Contact.cpp Commands.cpp
HDRS     = Contact.hpp PhoneBook.hpp
OBJS     = $(SRCS:.cpp=.o)
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g

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
