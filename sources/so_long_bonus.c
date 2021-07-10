#include "so_long_bonus.h"

void	structure_init(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
		all->keys[i++] = 0;
	i = 0;
	while (i < 6)
		all->flags[i++] = FALSE;
	all->map = NULL;
	all->line = NULL;
	all->mlx = NULL;
	all->img.img = NULL;
	all->win = NULL;
	all->max_map = (t_int){0, 0};
	all->collectibles = 0;
	all->movement = MOVE_SPEED * SCALE;
	all->moves_counter = 0;
	all->moves_buffer = 0.0;
	all->welcome_counter = 120;
	all->exit_counter = 120;
	all->frames = 0;
}

void	textures_init(t_all *all)
{
	my_mlx_tex_to_image(all, &all->tex[WATER], "textures/sea_tile.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_L], "textures/dolphin_L.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_R], "textures/dolphin_R.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH1], "textures/fish1.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH2], "textures/fish2.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH3], "textures/fish3.xpm");
	my_mlx_tex_to_image(all, &all->tex[WEED], "textures/sea_weed1.xpm");
	my_mlx_tex_to_image(all, &all->tex[EXIT], "textures/black_hole.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE1], "textures/mine1.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE2], "textures/mine2.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE3], "textures/mine3.xpm");
}

int	renderer(t_all *all)
{
	all->frames++;
	clear_window(all);
	keys_handler(all);
	draw_map(all);
	check_collectibles_and_exit(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	if (!all->flags[WITCHER])
		welcome_sign(all);
	check_mine(all);
	if (!all->flags[WITCHER])
		exit_sign(all);
	else
		witcher_signs(all, TRUE);
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

	if (argc != 2 && argc != 3)
		print_error_exit("Wrong number of arguments\n");
	if (!isvalid_extension(argv[1], ".ber"))
		print_error_exit("Invalid map extension\n");
	structure_init(&all);
	parser(&all, argv[1]);
	mlx_start(&all);
	if (argc == 3 && !ft_strncmp(argv[2], "--witcher", 10))
	{
		all.flags[WITCHER] = TRUE;
		witcher_textures_init(&all);
	}
	else if (argv[2])
		print_error_exit("Wrong second argument\n");
	else
		textures_init(&all);
	hooks_and_loops(&all);
	return (0);
}
