# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 20:24:51 by ffourati          #+#    #+#              #
#    Updated: 2015/03/01 22:29:53 by ffourati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean depclean re

CC := gcc

BIN := game_2048

LFT_DIR := libft
LFT_ := ft
LFT := $(LFT_DIR)/lib$(LFT_).a

SRC_DIR := srcs
SRC_ := main.c handle_command.c walk_grid.c get_movement.c \
		too_small.c display.c handler.c insert.c core.c refresh_display.c \
		infer_status.c show_status.c get_routine.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC_))

OBJ_DIR := obj
OBJ_ := $(SRC_:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ_))

HEADER_DIRS = includes $(LFT_DIR)/includes

IFLAGS = $(addprefix -I, $(HEADER_DIRS))
LFLAGS := $(addprefix -L, $(LFT_DIR)) $(addprefix -l, $(LFT_) ncurses)
CFLAGS := -Wall -Wextra -Werror -O3


all: $(OBJ_DIR) $(BIN)

$(BIN): $(OBJ) $(LFT) $(SHLIST) $(MLX)
	$(CC) -o $@ $(OBJ) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_DIRS)
	$(CC) $(CFLAGS) -c -o $@ $(IFLAGS) $<

$(OBJ_DIR):
	mkdir -p $@

$(LFT):
	(cd $(LFT_DIR) && make all)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

depclean:
	(cd $(LFT_DIR) && make fclean)

re: fclean all

