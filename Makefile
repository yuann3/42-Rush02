# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yiyli <etherealdt@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 12:04:40 by yiyli             #+#    #+#              #
#    Updated: 2024/03/16 15:29:44 by yiyli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
INCLUDES_DIR = include
INCLUDES = -I ${INCLUDES_DIR}
RM = rm -f
SRCS = $(wildcard ${SRCS_DIR}/*.c ${SRCS_DIR}/*/*.c)
OBJS = $(notdir $(SRCS:.c=.o))

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${INCLUDES} ${CFLAGS} $? -o $@ 

${OBJS} : ${SRCS}
	${CC} ${INCLUDES} ${CFLAGS} -c ${SRCS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re