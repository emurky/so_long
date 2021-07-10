#include "so_long.h"

int	scaled(double pos)
{
	return (pos / SCALE);
}

void	draw_map_sprites(t_all *all, t_int *pos)
{
	draw_square(&all->img, SCALE, *pos, WHITE);
	pos->x += (SCALE - SCALE / 2) / 2;
	pos->y += (SCALE - SCALE / 2) / 2;
	draw_square(&all->img, SCALE / 2, *pos, PLUM);
	pos->x -= (SCALE - SCALE / 2) / 2;
	pos->y -= (SCALE - SCALE / 2) / 2;
}

int	wall_collision(t_all *all, int dir)
{
	t_dbl	check_dir;

	if (dir == UP)
		check_dir = (t_dbl){0, 1};
	else if (dir == DOWN)
		check_dir = (t_dbl){0, -1};
	else if (dir == LEFT)
		check_dir = (t_dbl){-1, 0};
	else if (dir == RIGHT)
		check_dir = (t_dbl){1, 0};
	return (all->map
		[(int)(all->plr.y / SCALE - check_dir.y * DIR_K)]
		[(int)(all->plr.x / SCALE + check_dir.x * DIR_K)]
		== '1');
}

void	count_movements(t_all *all, double movement)
{
	all->moves_buffer += movement;
	if (all->moves_buffer >= SCALE)
	{
		all->moves_counter++;
		all->moves_buffer -= SCALE;
		ft_putnbr_fd(all->moves_counter, 1);
		ft_putstr_fd(" move\n", 1);
	}
}

void	move_player(t_all *all, int dir)
{
	if (!wall_collision(all, dir) && !all->flags[EXT])
	{
		if (!(all->keys[UP] && all->keys[DOWN])
			&& !(all->keys[LEFT] && all->keys[RIGHT]))
			count_movements(all, all->movement);
		if (dir == UP)
			all->plr.y -= all->movement;
		else if (dir == DOWN)
			all->plr.y += all->movement;
		else if (dir == LEFT)
			all->plr.x -= all->movement;
		else if (dir == RIGHT)
			all->plr.x += all->movement;
	}
}
