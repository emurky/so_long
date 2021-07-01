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

void	free_malloc_pointers(t_all *all)
{
	if (all->line)
		free(all->line);
	// if (all->ray.z_buff)
	// 	free(all->ray.z_buff);
	// if (all->ray.sprites)
	// 	free(all->ray.sprites);
	// printf("Allocated memory were freed\n");
}

void	clean_all(t_all *all)
{
	free_array(all->map);
	clean_mlx(all);
	free_malloc_pointers(all);
}

void	print_error_exit(char *err_str)
{
	write(2, "Error\n", 6);
	write(2, err_str, ft_strlen(err_str));
	exit(EXIT_FAILURE);
}

void	leave(int error, char *err_str, t_all *all, char **array)
{
	if (array)
		free_array(array);
	if (error)
	{
		write(2, "Error\n", 6);
		write(2, err_str, ft_strlen(err_str));
		clean_all(all);
		write(2, "So long...\n", 11);
		exit(EXIT_FAILURE);
	}
	clean_all(all);
	write(1, "So long and thanks for all the fish!\n", 37);
	exit(EXIT_SUCCESS);
}
