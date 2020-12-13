

NAME		= minishell

CFILES		=  main.c


SRCS		= $(addprefix ${FOLDER}/, ${CFILES})
OFILES		= ${SRCS:.c=.o}

HEADER		= includes
FOLDER		= srcs

FT_PRINTF	= libft/srcs/ft_printf

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

fclean: 	clean
				@${RM} ${NAME}
				@make fclean -C $(FT_PRINTF)

re: 		fclean all

.PHONY: all clean fclean re