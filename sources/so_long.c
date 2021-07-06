#include "so_long.h"

void	structure_init(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
		all->keys[i++] = 0;
	i = 0;
	while (i < 3)
		all->flags[i++] = false;
	all->map = NULL;
	all->line = NULL;
	all->mlx = NULL;
	all->img.img = NULL;
	all->win = NULL;
	all->max_map = (t_pnt){0, 0};

	all->tex_coef = (double)SCALE / (double)TEX_RES;
	// t_pnt tex_res;
	// all->tex.img = mlx_xpm_file_to_image(all->mlx, "./textures/sea_tile.xpm", &tex_res.x, &tex_res.y);
	// all->tex.addr = mlx_get_data_addr(all->tex.img, &all->tex.bpp, &all->tex.linelen, &all->tex.endian);
// printf("%f\n", all->tex_coef);
	all->collectibles = 0;
	all->movement = 0.0;
	all->moves_counter = 0;
	all->moves_buffer = 0.0;
	all->welcome = 120;
	all->exit_counter = 120;
}

void	sign_background(t_all *all, int width)
{
	int		i;
	int		j;

	j = all->window.y / 2 - 15;
	while (j <= all->window.y / 2 + 5)
	{
		i = all->window.x / 2 - width / 2;
		while (i <= all->window.x / 2 + width / 2)
		{
			my_mlx_pixel_put(&all->img, i, j, SKY_BLUE);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}

void	welcome_sign(t_all *all)
{
	if (all->window.y >= 30 && all->window.x >= 160)
	{
		if (all->welcome > 0)
		{
			sign_background(all, 160);
			mlx_string_put(all->mlx, all->win,
				all->window.x / 2 - 68, all->window.y / 2,
				DARK_BROWN, "Welcome to \"So_long\"");
			all->welcome--;
		}
	}
}

void	check_collectibles(t_all *all)
{
	int		i;
	int		j;

	j = (int)(all->plr.y / SCALE + EAT_RAD);
	i = (int)(all->plr.x / SCALE + EAT_RAD);
	if (all->map[j][i] == 'C')
	{
		all->map[j][i] = '0';
		all->collectibles--;
	}
}

void	check_exit(t_all *all)
{
	if (!all->collectibles && all->map
		[(int)(all->plr.y / SCALE)][(int)(all->plr.x / SCALE)] == 'E')
		all->flags[EXT] = true;
	if (all->window.y >= 30 && all->window.x >= 300 && all->flags[EXT])
	{
		sign_background(all, 342);
		mlx_string_put(all->mlx, all->win,
			all->window.x / 2 - 155, all->window.y / 2,
			DARK_BROWN, "YOU WON! So long and thanks for all the fish!");
		all->exit_counter--;
		if (!all->exit_counter && all->flags[EXT])
			close_window(all);
	}
	else if (all->flags[EXT])
		close_window(all);
}

int	renderer(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	keys_handler(all);
	draw_map(all);
	check_collectibles(all);
	// draw_textured_square(all, (t_pnt){50,50});
	// printf("%X color\n", my_mlx_pixel_get(&all->img, 100, 100));
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	welcome_sign(all);
	check_exit(all);
	
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

void	textures_init(t_all *all)
{
	my_mlx_tex_to_image(all, &all->tex, "textures/sea_tile.xpm");
	my_mlx_tex_to_image(all, &all->tex2, "textures/dolphin.xpm");
	my_mlx_tex_to_image(all, &all->tex3, "textures/fish2.xpm");
	my_mlx_tex_to_image(all, &all->tex4, "textures/sea_weed.xpm");
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

// printf("%d win width %d win height %d multipl\n", all.window.x, all.window.y, all.window.x * all.window.y);
	textures_init(&all);
	hooks_and_loops(&all);
	return (0);
}
