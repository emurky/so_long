#include "so_long.h"

void	structure_init(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
		all->keys[i++] = 0;
	i = 0;
	while (i < 4)
		all->flags[i++] = FALSE;
	all->map = NULL;
	all->line = NULL;
	all->mlx = NULL;
	all->img.img = NULL;
	all->win = NULL;
	all->max_map = (t_pnt){0, 0};
	all->tex_k = (double)SCALE / (double)TEX_RES;
	all->collectibles = 0;
	all->movement = MOVE_SPEED * SCALE;
	all->moves_counter = 0;
	all->moves_buffer = 0.0;
	all->welcome_counter = 120;
	all->exit_counter = 120;
}

void	textures_init(t_all *all)
{
	my_mlx_tex_to_image(all, &all->tex[WATER], "textures/sea_tile.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_L], "textures/dolphin_L.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_R], "textures/dolphin_R.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH], "textures/fish3.xpm");
	my_mlx_tex_to_image(all, &all->tex[WEED], "textures/sea_weed2.xpm");
	my_mlx_tex_to_image(all, &all->tex[EXIT], "textures/black_hole.xpm");
}

int	renderer(t_all *all)
{
	clear_window(all);
	keys_handler(all);
	draw_map(all);
	check_collectibles_and_exit(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	welcome_sign(all);
	exit_sign(all);
	if (COUNTER && SCALE >= 42)
		move_counter(all);
	return (0);
}

void	hooks_and_loops(t_all *all)
{
	mlx_hook(all->win, 2, 1L << 0, key_pressed, all);
	mlx_hook(all->win, 3, 1L << 1, key_released, all);
	mlx_hook(all->win, 17, 1L << 17, close_window, all);
	mlx_loop_hook(all->mlx, renderer, all);
	mlx_loop(all->mlx);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		print_error_exit("Wrong number of arguments\n");
	if (!isvalid_extension(argv[1], ".ber"))
		print_error_exit("Invalid map extension\n");
	structure_init(&all);
	parser(&all, argv[1]);
	mlx_start(&all);
	textures_init(&all);
	hooks_and_loops(&all);
	return (0);
}
