#include "so_long.h"

int	is_interior(char c)
{
	return (c == '0' || c == 'C' || c == 'E' || c == 'P');
}

int	check_neighbours(t_map map, int row, int col)
{
	if (row == 0 || row == map.height - 1 || col == 0 || col == map.width - 1)
		return (FALSE);
	return (TRUE);
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
			if (is_interior(map.map[j][i]) && !check_neighbours(map, j, i))
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

	j = scaled(all->plr.y);
	i = scaled(all->plr.x);
	if (all->map[j][i] == 'C')
	{
		all->map[j][i] = '0';
		all->collectibles--;
	}
	if (!all->collectibles && all->map
		[scaled(all->plr.y)][scaled(all->plr.x)] == 'E')
		all->flags[EXT] = TRUE;
}
