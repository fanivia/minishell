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

CFILES		=  \
						ft_atoi.c ft_bzero.c ft_calloc.c \
		 				ft_isalnum.c ft_isalpha.c ft_isascii.c \
						ft_isdigit.c ft_isprint.c ft_memccpy.c \
						ft_memchr.c ft_memcmp.c ft_memcpy.c \
						ft_memmove.c ft_memset.c ft_strchr.c \
						ft_strdup.c ft_strlcat.c ft_strlcpy.c \
						ft_strlen.c ft_strncmp.c ft_strnstr.c \
						ft_strrchr.c ft_tolower.c ft_toupper.c \
						ft_strjoin.c ft_substr.c ft_split.c \
						ft_strtrim.c ft_itoa.c ft_strmapi.c \
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
						ft_putnbr_fd.c ft_c_to_str.c ft_intlen_base.c \
						ft_intlen.c ft_itoa_base.c ft_lstadd_back.c \
						ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
						ft_lstiter.c ft_lstlast.c ft_lstmap.c \
						ft_lstnew.c ft_lstsize.c ft_str_end.c \
						ft_strequ.c ft_uintlen.c ft_uitoa.c \
						ft_strdel.c ft_is_space.c ft_atof.c \
						ft_ssplit.c ft_str_c_count.c ft_strlen_c.c\
						ft_strcmp.c \
						ft_is_in_stri.c get_next_line.c \
						ft_free_array.c

SRCS		= $(addprefix ${FOLDER}/, ${CFILES})
OFILES		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= srcs

FT_PRINTF	= $(FOLDER)/ft_printf

CC				= gcc
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

fclean: 	clean
				@${RM} ${NAME}
				@make fclean -C $(FT_PRINTF)

re: 		fclean all

.PHONY: all clean fclean re
