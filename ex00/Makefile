# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:46:56 by schahid           #+#    #+#              #
#    Updated: 2023/05/13 16:50:40 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= btc
SRC= BitcoinExchange.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJ)
		@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
		@echo "BitcoinExchange compiled successfully ✅"
%.o: %.cpp
		@$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		@rm -rf $(OBJ)
		@echo "BitcoinExchange object files cleaned successfully 🗑"
fclean:
		@rm -rf $(OBJ)
		@rm -rf $(NAME)
		@echo "BitcoinExchange object files and BitcoinExchange cleaned successfully 🗑"

re: fclean all