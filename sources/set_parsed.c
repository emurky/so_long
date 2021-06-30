#include "so_long.h"

void	set_window_size(t_all *all)
{
	t_pnt	display_res;

	all->window.x = all->max_map.x * SCALE;
	all->window.y = all->max_map.y * SCALE;
	mlx_get_screen_size(&display_res.x, &display_res.y);
	if (display_res.x < all->window.x || display_res.y < all->window.y)
		leave(ERR, ERR_WIN, all, NULL);
}

void	init_player(t_all *all, int i, int j)
{
	if (!all->flags[PLR])
	{
		set_player_pos(all, i, j);
		set_player_dir(all, M_PI_2);
		all->flags[PLR] = true;
	}
	else
		leave(ERR, ERR_PLR_DBL, all, NULL);
}

void	set_player(t_all *all, char **map)
{
	int		i;
	int		j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				init_player(all, i, j);
			else if (map[j][i] == 'E')
			{
				if (!all->flags[EXT])
					all->flags[EXT] = true;
				else
					leave(ERR, ERR_EXT, all, NULL);
			}
			else if (map[j][i] == 'C')
				all->flags[COL] = true;
			i++;
		}
		j++;
	}
}
