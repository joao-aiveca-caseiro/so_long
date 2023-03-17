LIBFT		= ./libft/libft.a
SRCS		= so_long.c\
				map_content_checks.c\
				map_path_check.c\
				map_read_validate.c\
				img_utils.c\
				events.c\
				enemies.c\
				animations.c
OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
LFLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKE} all -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} 


all:		$(NAME)

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${RM} $(NAME)
			${MAKE} fclean -C ./libft

re:			fclean all