NAME= PmergeMe
SRC= PmergeMe.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98 -g

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "PmergeMe compiled successfully ✅"
		
%.o: %.cpp
		@$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)
		@echo "PmergeMe object files cleaned successfully 🗑"
fclean:
		@rm -rf $(OBJ)
		@rm -rf $(NAME)
		@echo "PmergeMe object files and PmergeMe cleaned successfully 🗑"

re: fclean all