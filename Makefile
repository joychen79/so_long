# so_long
NAME				=	so_long

SOLONG_SRC			=	src/so_long.c \
						src/render_game.c \
						src/read_map.c \
						src/utils.c \
						src/validate_map.c

OBJS				= $(SOLONG_SRC:.c=.o)

# Libft
LIBFT				=	libft.a
LIBFT_SRC			=	./libft/

# Compiler
CC					=	gcc
RM					=	rm -f
CFLAGS				=	-Wall -Werror -Wextra 
LIBX_FLAGS			=	-Imlx -lmlx -framework OpenGL -framework AppKit


# Rules
all:		$(LIBFT) $(NAME)

$(LIBFT):
			@make -C libft 
			
$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(LIBX_FLAGS) $(OBJS) $(LIBFT_SRC)$(LIBFT) -o $(NAME)

clean:
			@make -C libft fclean
			@$(RM) $(OBJS)


fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re