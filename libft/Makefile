# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffourati <ffourati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 19:14:22 by ffourati          #+#    #+#              #
#    Updated: 2015/03/01 22:30:04 by ffourati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

CFLAGS = -Wall -Wextra -Werror -O3

CC := gcc

NAME = libft.a

SRCS_DIR = srcs/

INCL_DIR = includes/

SRCS_ = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memcmp.c \
		ft_memmove.c ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strcat.c \
		ft_strncat.c ft_strlcat.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c \
		ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c ft_strrchr.c \
		ft_memchr.c ft_atoi.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c \
		ft_strstr.c ft_strnstr.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		ft_strsplit.c ft_itoa.c ft_realloc.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c \
		ft_strlen_isxnot.c ft_isspace.c ft_strrev.c ft_lnkclear.c \
		ft_lstappend.c ft_inssort_ints.c ft_inssort_strings.c \
		ft_dlstnew.c ft_dlstadd.c ft_dlstins.c ft_dlstdelone.c ft_dlstdel.c \
		ft_memrev.c ft_strndup.c ft_strnjoin.c ft_puts.c ft_putnstr_fd.c \
		ft_putnstr.c ft_strtol.c ft_putlhex.c ft_putlhex_fd.c ft_putlong_fd.c \
		ft_putlong.c ft_fmtputlhex.c ft_fmtputlhex_fd.c ft_tee_s.c ft_itoa_r.c \
		ft_memrchr.c

SRCS = $(patsubst %.c,$(SRCS_DIR)%.c,$(SRCS_))

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(SRCS_:.c=.o))





all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(INCL_DIR)
	$(CC) -o $@ -c $(CFLAGS) -I$(INCL_DIR) $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
