# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugo-mar <hugo-mar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 10:42:29 by hugo-mar          #+#    #+#              #
#    Updated: 2025/08/06 16:21:05 by hugo-mar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = randomGenAndIdentify

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS_PATH = ./srcs/

SRCS = $(SRCS_PATH)Base.cpp $(SRCS_PATH)main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
