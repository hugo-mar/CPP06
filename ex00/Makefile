# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 00:49:34 by hugo-mar          #+#    #+#              #
#    Updated: 2025/08/05 00:53:11 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_PATH = ./srcs/

SRC = $(SRCS_PATH)main.cpp $(SRCS_PATH)ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
