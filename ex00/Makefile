# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schahid <schahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 11:46:56 by schahid           #+#    #+#              #
#    Updated: 2023/05/12 15:12:39 by schahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= btc
SRC= BitcoinExchange.cpp main.cpp
OBJ= $(SRC:.cpp=.o)
CPP= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 -g

$(NAME): $(OBJ)
		$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
		
%.o: %.cpp
		$(CPP) $(CPPFLAGS) -c $<

all: $(NAME)

clean:
		rm -rf $(OBJ)
		
fclean:
		rm -rf $(OBJ)
		rm -rf $(NAME)

re: fclean all