# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/03 22:37:12 by student           #+#    #+#              #
#    Updated: 2020/06/09 01:59:58 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFILES		=	ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
                ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
                ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
                ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
                ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
                ft_substr.c ft_strjoin.c ft_strtrim.c ft_strtrim.c ft_split.c \
                ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
                ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
                ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
                ft_lstclear.c ft_lstiter.c ft_lstmap.c \
                get_next_line_utils.c get_next_line.c

SRCS		= $(addprefix ${FOLDER}/, ${CFILES})
OFILES		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= srcs

FT_PRINTF	= $(FOLDER)/ft_printf

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

$(NAME):	${OFILES}
				@make -C $(FT_PRINTF)
				@cp $(FT_PRINTF)/libftprintf.a ./$(NAME)
				@ar -rcs ${NAME} ${OFILES}

%.o: %.c
				@${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}

all:			${NAME}

clean:
			@${RM} ${OFILES}
			@make clean -C $(FT_PRINTF)

fclean:			clean
				@${RM} ${NAME}
				@make clean -C $(FT_PRINTF)

re: 		fclean all

.PHONY: all clean fclean re
