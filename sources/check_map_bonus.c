#include "so_long_bonus.h"

int	is_interior(char c)
{
	return (c == '0' || c == 'C' || c == 'E' || c == 'P' || c == 'M');
}

int	check_continuity(t_map map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map.height)
	{
		i = 0;
		while (i < map.width)
		{
			if (is_interior(map.map[j][i])
				&& (j == 0 || j == map.height - 1
				|| i == 0 || i == map.width - 1))
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

int	check_map_line(t_all *all, char *line)
{
	char	*head;
	int		line_len;

	head = line;
	if (!(*line))
	{
		if (!all->flags[EOM])
			all->flags[EOM] = TRUE;
		return (0);
	}
	while (*line)
	{
		if (!(is_interior(*line) || *line == '1'))
			return (-1);
		line++;
	}
	line_len = ft_strlen(head);
	if (line_len != all->max_map.x)
		return (-2);
	return (1);
}

void	check_collectibles_and_exit(t_all *all)
{
	int		i;
	int		j;

	j = (int)(all->plr.y / SCALE);
	i = (int)(all->plr.x / SCALE);
	if (all->map[j][i] == 'C')
	{
		all->map[j][i] = '0';
		all->collectibles--;
	}
	if (!all->collectibles && all->map
		[(int)(all->plr.y / SCALE)][(int)(all->plr.x / SCALE)] == 'E')
		all->flags[EXT] = TRUE;
}

void	check_mine(t_all *all)
{
	if (all->map[(int)(all->plr.y / SCALE)][(int)(all->plr.x / SCALE)] == 'M')
	{
		all->flags[LST] = TRUE;
		if (all->window.y >= 30 && all->window.x >= 164 && all->flags[LST])
		{
			sign_background(all, 163);
			mlx_string_put(all->mlx, all->win,
				all->window.x / 2 - 68, all->window.y / 2,
				DARK_BROWN, "YOU LOST! So long...");
			all->exit_counter--;
			if (!all->exit_counter && all->flags[LST])
				close_window(all);
		}
		else if (all->flags[LST])
		{
			ft_putstr_fd("YOU LOST! So long...\n", 1);
			close_window(all);
		}
	}
}
