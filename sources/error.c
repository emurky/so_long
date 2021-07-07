#include "so_long.h"

void	free_array(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
		array = NULL;
	}
}

void	clean_mlx(t_all *all)
{
	int		i;

	i = 0;
	if (all->mlx && all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->mlx && all->img.img)
		mlx_destroy_image(all->mlx, all->img.img);
	while (i < 6)
	{
		if (all->mlx && all->tex[i].img)
			mlx_destroy_image(all->mlx, all->tex[i].img);
		i++;
	}
}

void	clean_all(t_all *all)
{
	free_array(all->map);
	clean_mlx(all);
	if (all->line)
		free(all->line);
}

void	print_error_exit(char *err_str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err_str, 2);
	exit(EXIT_FAILURE);
}

void	leave(int error, char *err_str, t_all *all)
{
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err_str, 2);
		clean_all(all);
		ft_putstr_fd("So long...\n", 2);
		exit(EXIT_FAILURE);
	}
	clean_all(all);
	ft_putstr_fd("So long and thanks for all the fish!\n", 1);
	exit(EXIT_SUCCESS);
}
