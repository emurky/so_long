#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# include "defines.h"
# include "structures.h"
# include "error.h"
# include "colors.h"
# include "mlx/mlx.h"
# include "libft/libft.h"

/*			so_long.c */
void		structure_init(t_all *all);
void		textures_init(t_all *all);
int			renderer(t_all *all);
void		hooks_and_loops(t_all *all);

/*			interface.c */
void		clear_window(t_all *all);
void		sign_background(t_all *all, int width);
void		welcome_sign(t_all *all);
void		exit_sign(t_all *all);
void		move_counter(t_all *all);

/*			my_mlx_utils.c */
int			is_transparent(int trgb);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			my_mlx_pixel_get(t_img *img, int x, int y);
void		my_mlx_tex_to_image(t_all *all, t_img *tex, char *path);
void		mlx_start(t_all *all);

/*			parser.c */
void		malloc_map(t_all *all, t_list **head);
void		check_map(t_all *all);
void		get_map_line(t_all *all, t_list **head, int line_read);
void		parse_map(t_all *all, int fd, int line_read);
void		parser(t_all *all, char *cub);

/*			set_parsed.c */
int			isvalid_extension(char *file, const char *ext);
void		set_window_size(t_all *all);
void		init_player(t_all *all, int i, int j);
void		init_exit(t_all *all);
void		set_map_chars(t_all *all, char **map);

/*			check_map.c */
int			is_interior(char c);
int			check_neighbours(t_map map, int row, int col);
int			check_continuity(t_map map);
int			check_map_line(t_all *all, char *line);
void		check_collectibles_and_exit(t_all *all);

/*			key_hooks.c */
int			close_window(t_all *all);
int			key_pressed(int key, t_all *all);
int			key_released(int key, t_all *all);
void		keys_handler(t_all *all);

/*			player_move.c */
int			wall_collision(t_all *all, int dir);
void		count_movements(t_all *all, double movement);
void		move_player(t_all *all, int dir);

/*			draw_map.c */
void		draw_square(t_img *img, int width, t_pnt pos, int color);
void		draw_map_sprites(t_all *all, t_pnt *pos);	//in player_move.c
void		draw_textured_square(t_all *all, t_img *tex, t_pnt pos);
void		map_chars_switcher(t_all *all, char map_char, t_pnt pos);
void		draw_map_squares(t_all *all, char **map);
void		draw_map(t_all *all);

/*			error.c */
void		free_array(char **array);
void		clean_mlx(t_all *all);
void		clean_all(t_all *all);
void		print_error_exit(char *err_str);
void		leave(int error, char *err_str, t_all *all);

#endif
//43
