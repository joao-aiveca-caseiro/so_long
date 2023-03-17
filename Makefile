LIBFT		= ./libft/libft.a
SRCS		= sources/so_long.c\
				sources/map_content_checks.c\
				sources/map_path_check.c\
				sources/map_read_validate.c\
				sources/img_utils.c\
				sources/events.c\
				sources/player.c\
				sources/utils.c
SRCS_BONUS	= bonus/so_long_bonus.c\
				bonus/map_content_checks_bonus.c\
				bonus/map_path_check_bonus.c\
				bonus/map_read_validate_bonus.c\
				bonus/img_utils_bonus.c\
				bonus/events_bonus.c\
				bonus/enemies_bonus.c\
				bonus/animations_bonus.c\
				bonus/player_bonus.c\
				bonus/utils_bonus.c
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS		= ${SRCS_BONUS:.c=.o}
NAME		= so_long
NAME_BONUS		= so_long_bonus
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
LFLAGS		= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.c.o:
			${CC} ${CFLAGS} -I/usr/include -Imlx_linux -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKE} all -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ${LIBFT} -o ${NAME} 

$(NAME_BONUS):	${BONUS_OBJS}
			${MAKE} all -C ./libft
			${CC} ${CFLAGS} ${BONUS_OBJS} ${LFLAGS} ${LIBFT} -o ${NAME_BONUS} 

bonus:		${NAME_BONUS}

all:		$(NAME) $(NAME_BONUS)

clean:
			${RM} ${OBJS} ${BONUS_OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${RM} ./libft/libft.a
			${RM} $(NAME) ${NAME_BONUS}

re:			fclean all