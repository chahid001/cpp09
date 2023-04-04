NAME= RPN
SRC= RPN.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -g -std=c++98

$(NAME): $(OBJ)
		$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
		
%.o: %.cpp
		$(CPP) $(CPPFLAGS) -c $<

clean:
		rm -rf $(OBJ)
		
fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)

re: fclean all