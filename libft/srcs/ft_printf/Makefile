# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fanivia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/02 19:38:47 by fanivia           #+#    #+#              #
#    Updated: 2020/08/02 20:41:32 by fanivia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

C_FILES		= 	ft_printf.c ft_print_char.c ft_print_digit.c ft_print_hex.c \
				ft_print_ptr.c ft_print_ud.c

O_FILES		=	${C_FILES:.c=.o}

HEADER		=	../../includes

CC			=	gcc
C_FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

all:		$(NAME)

$(NAME):	${O_FILES}
			@ar rc $(NAME) ${O_FILES}
			ranlib $(NAME)

%.o: %.c
			${CC} -c ${C_FLAGS} -o $@ $< -I ${HEADER}

clean:
			@${RM} ${O_FILES}

fclean:		clean
			@${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re
