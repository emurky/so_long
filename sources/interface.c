#include "so_long.h"

void	clear_window(t_all *all)
{
	int		i;
	int		j;

	j = 0;
	while (j < all->window.y)
	{
		i = 0;
		while (i < all->window.x)
		{
			my_mlx_pixel_put(&all->img, i, j, BLACK);
			i++;
		}
		j++;
	}
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
		if (all->welcome_counter > 0)
		{
			sign_background(all, 160);
			mlx_string_put(all->mlx, all->win,
				all->window.x / 2 - 68, all->window.y / 2,
				DARK_BROWN, "Welcome to \"So_long\"");
			all->welcome_counter--;
		}
	}
}

void	exit_sign(t_all *all)
{
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

void	move_counter(t_all *all)
{
	char	*counter_itoa;
	char	*counter;

	counter_itoa = NULL;
	counter = NULL;
	counter_itoa = ft_itoa(all->moves_counter);
	if (!counter_itoa)
		leave(ERR, ERR_MALLOC, all);
	counter = ft_strjoin(counter_itoa, " move");
	if (!counter)
	{
		free(counter_itoa);
		leave(ERR, ERR_MALLOC, all);
	}
	mlx_string_put(all->mlx, all->win, SCALE * 0.5, 15, BLACK, counter);
	free(counter_itoa);
	free(counter);
}
