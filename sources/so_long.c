#include "so_long.h"

void	structure_init(t_all *all)
{
	int		i;

	i = 0;
	while (i < 6)
		all->keys[i++] = 0;
	i = 0;
	while (i < 4)
		all->flags[i++] = false;
	all->map = NULL;
	all->line = NULL;
	all->mlx = NULL;
	all->img.img = NULL;
	all->win = NULL;
	all->max_map = (t_pnt){0, 0};
}

int	renderer(t_all *all)
{
	mlx_clear_window(all->mlx, all->win);
	keys_handler(all);
	draw_map(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	return (0);
}

void	hooks_and_loops(t_all *all)
{
	mlx_hook(all->win, 2, 1L <<0, key_pressed, all);
	mlx_hook(all->win, 3, 1L <<1, key_released, all);
	mlx_hook(all->win, 17, 1L <<17, close_window, all);
	mlx_loop_hook(all->mlx, renderer, all);
	mlx_loop(all->mlx);
}

int	main(int argc, char **argv)
{
	t_all	all;

	structure_init(&all);
	if (argc != 2)
		print_error_exit("Wrong number of arguments\n");
	if (!isvalid_extension(argv[1], ".ber"))
		print_error_exit("Invalid map extension\n");
	parser(&all, argv[1]);
	mlx_start(&all);
	hooks_and_loops(&all);
	return (0);
}
