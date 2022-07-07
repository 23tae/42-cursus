# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taehooki <taehooki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 21:00:19 by taehooki          #+#    #+#              #
#    Updated: 2022/07/07 22:42:37 by taehooki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			ft_print_char.c \
			ft_print_dec.c \
			ft_print_hex.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
AR		= ar crs
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp $(LIBFT) ./$(NAME)
			$(AR) $(NAME) $(OBJS)

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all, clean, fclean, re
