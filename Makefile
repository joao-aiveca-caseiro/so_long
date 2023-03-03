LIBFT		= ./libft/libft.a
SRCS		= so_long.c
OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKE} all -C ./libft
			${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${LIBFT} -o ${NAME} 


all:		$(NAME)

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${RM} $(NAME)
			${MAKE} fclean -C ./libft

re:			fclean all