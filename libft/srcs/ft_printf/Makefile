# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fanivia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 21:56:15 by fanivia           #+#    #+#              #
#    Updated: 2020/09/24 21:56:18 by fanivia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CFILES		= \
					ft_printf.c \
					ft_convert.c \
					ft_convert_int.c \
					ft_parse.c \
					ft_utils.c \
					utils.c

OFILES		= ${CFILES:.c=.o}

HEADER		= ../../includes

CC				= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

all:			${NAME}

${NAME}:		${OFILES}
				@ar -rcs ${NAME} ${OFILES}

%.o: %.c
					@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
			@${RM} ${OFILES}

fclean: 	clean
				@${RM} ${NAME}

re: 		fclean all

.PHONY: all clean fclean re
