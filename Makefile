SRCSDIR				= ./sources
OBJSDIR				= ./objs
DEPSDIR				= ./deps

SRCS				= $(addprefix $(SRCSDIR)/, \
						so_long.c \
						interface.c \
						my_mlx_utils.c \
						parser.c \
						set_parsed.c \
						check_map.c \
						key_hooks.c \
						player_move.c \
						draw_map.c \
						error.c )
OBJS				= $(SRCS:.c=.o)
DEPS				= $(SRCS:.c=.d)

B_SRCS				= $(addprefix $(SRCSDIR)/, \
						so_long_bonus.c \
						interface.c \
						my_mlx_utils.c \
						parser.c \
						set_parsed_bonus.c \
						check_map_bonus.c \
						key_hooks.c \
						player_move_bonus.c \
						draw_map_bonus.c \
						error.c \
						witcher_bonus.c )
B_OBJS				= $(B_SRCS:.c=.o)
B_DEPS				= $(B_SRCS:.c=.d)

NAME				= so_long

CC 					= gcc
RM 					= rm -f
CFLAGS				= -Wall -Wextra -Werror -O2 #-g -fsanitize=address
CPPFLAGS			= -MMD -I. -I./includes
MLX_FLAGS			= -framework OpenGL -framework AppKit -lz

LIBS				= \
						-L./libft -lft \
						-L./mlx -lmlx $(MLX_FLAGS)

all:				$(NAME)

$(NAME):			$(OBJS)
					$(MAKE) -C ./libft -j4
					$(MAKE) -C ./mlx -j4
					$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

bonus:				$(B_OBJS)
					$(MAKE) -C ./libft -j4
					$(MAKE) -C ./mlx -j4
					$(CC) $(CFLAGS) $(B_OBJS) $(LIBS) -o $(NAME)

-include			$(DEPS)
-include			$(B_DEPS)

clean:
					$(MAKE) clean -C ./libft
					$(MAKE) clean -C ./mlx
					$(RM) $(OBJS) $(B_OBJS) $(DEPS) $(B_DEPS)

fclean:				clean
					$(RM) ./libft/libft.a
					$(RM) ./mlx/libmlx.a
					$(RM) $(NAME)

re:					fclean all


# *************** libft rules *************** #
libft:
					$(MAKE) -C ./libft

libft_clean:
					$(MAKE) clean -C ./libft

libft_fclean:
					$(MAKE) fclean -C ./libft

libft_re:
					$(MAKE) re -C ./libft
# ******************************************** #

sc:
					rm -rf *.o *.a */*.o */*.a */*.d *.d 'so_long '* so_long

.PHONY:				all clean fclean re bonus \
					libft libft_clean libft_fclean libft_re \
					sc

#.SILENT:
# gcc -Wall -Wextra -Werror -framework OpenGL -framework AppKit -lz 
# -L./libft -lft -L./mlx -lmlx -g sources/*.c -o so_long
# leaks --atExit -- ./so_long map.ber
