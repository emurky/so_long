#include "so_long.h"

void	set_player_pos(t_all *all, int x, int y)
{
	all->plr.x = x * SCALE + SCALE / 2.0;
	all->plr.y = y * SCALE + SCALE / 2.0;
}

void	set_player_dir(t_all *all, double dir)
{
	all->plr.dir = dir;
}

int	wall_collision_y(t_all *all, double dir)
{
	return (all->map
		[(int)floor(all->plr.y / SCALE - sin(all->plr.dir + dir) * 0.52)]
		[(int)floor(all->plr.x / SCALE)]
		== '1');
}

int	wall_collision_x(t_all *all, double dir)
{
	return (all->map
		[(int)floor(all->plr.y / SCALE)]
		[(int)floor(all->plr.x / SCALE + cos(all->plr.dir + dir) * 0.52)]
		== '1');
}

void	count_movements(t_all *all, double movement)
{
	all->moves_buffer += fabs(movement);
	if (all->moves_buffer >= SCALE)
	{
		all->moves_counter++;
		all->moves_buffer -= SCALE;
		printf("%d move\n", all->moves_counter);
	}
}

void	move_player(t_all *all, double dir)
{
	double	movement;

	movement = 0.0;
	if (!wall_collision_x(all, dir))
	{
		movement = cos(all->plr.dir + dir) * MOVE_SPEED * SCALE;
		all->plr.x += movement;
		count_movements(all, movement);
	}
	if (!wall_collision_y(all, dir))
	{
		movement = sin(all->plr.dir + dir) * MOVE_SPEED * SCALE;
		all->plr.y -= movement;
		count_movements(all, movement);
	}
}
