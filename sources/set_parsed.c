#include "so_long.h"

int	isvalid_extension(char *file, const char *ext)
{
	int		ext_len;
	int		file_len;

	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (ft_strncmp(file + file_len - ext_len, ext, ext_len + 1))
		return (FALSE);
	return (TRUE);
}

void	set_window_size(t_all *all)
{
	t_int	display_res;

	all->window.x = all->max_map.x * SCALE;
	all->window.y = all->max_map.y * SCALE;
	mlx_get_screen_size(&display_res.x, &display_res.y);
	if (display_res.x < all->window.x || display_res.y < all->window.y)
		leave(ERR, ERR_WIN, all);
}

void	init_player(t_all *all, int i, int j)
{
	if (!all->flags[PLR])
	{
		all->plr.x = i * SCALE + SCALE / 2.0;
		all->plr.y = j * SCALE + SCALE / 2.0;
		all->flags[PLR] = TRUE;
	}
	else
		leave(ERR, ERR_PLR_DBL, all);
}

void	init_exit(t_all *all)
{
	if (!all->flags[EXT])
		all->flags[EXT] = TRUE;
	else
		leave(ERR, ERR_EXT, all);
}

void	set_map_chars(t_all *all, char **map)
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
				init_exit(all);
			else if (map[j][i] == 'C')
				all->collectibles++;
			i++;
		}
		j++;
	}
}
