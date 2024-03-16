# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 12:04:40 by yiyli             #+#    #+#              #
#    Updated: 2024/03/16 15:09:21 by yiyli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
INCLUDES_DIR = include
SRCS = $(SRCS_DIR)/
OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean