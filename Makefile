# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welee <welee@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:28:52 by yiyli             #+#    #+#              #
#    Updated: 2024/03/17 18:46:33 by mamu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= rush-02

DATA_DIR := data
SOURCE_DIR := srcs
INCLUDE_DIR := include
OBJECT_DIR := objs

CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(INCLUDE_DIR)

NORM := norminette
NORM_FLAGS := -R CheckForbiddenSourceHeader -R CheckDefine

# Helper function to list all files matching pattern recursively
# e.g. List all *.c files in srcs/ folder
rwildcard = $(shell find $(1) -type f -name '$(2)')

# Find all c files, and convert to o files
# e.g. srcs/main.c srcs/dict/dict.c => objs/main.o objs/dict/dict.o
sources := $(call rwildcard,$(SOURCE_DIR),*.c)
headers := $(call rwildcard,$(INCLUDE_DIR),*.h)
objects := $(sources:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)

.PHONY: all
all: $(NAME)

# How to compile binary from all o files
# e.g. objs/main.o objs/dict/dict.o => rush-02
$(NAME): $(objects)
	$(CC) $(CFLAGS) $^ -o $@

# How to compile each c file to o file
# Also, consider h file, though it is not included for compilation
# e.g. srcs/dict/dict.c (srcs/dict/dict.h) => objs/dict/dict.o
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDE_DIR)/%.h
	@$(NORM) $(NORM_FLAGS) $<
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJECT_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
