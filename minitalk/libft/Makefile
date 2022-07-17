# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 00:23:27 by taehooki          #+#    #+#              #
#    Updated: 2022/07/17 23:47:55 by taehooki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_printf.c \
		ft_print_char.c \
		ft_print_dec.c \
		ft_print_hex.c \
		ft_abs.c \
		ft_pow.c \
		ft_digitnum.c \
		ft_isspace.c \
		ft_isoverflow.c \
		ft_strcjoin.c \
		ft_putstr_color_fd.c

CC = gcc
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -c

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rsc $(NAME) $^
	@echo "libft made"

%.o : %.c
	@$(CC) $(CFLAGS) $< -o $@ -I .

clean :
	@rm -f $(OBJS)
	@echo "libft cleaned"

fclean : clean
	@rm -f $(NAME)

re :
	@make fclean
	@make all

.PHONY: all clean fclean re 