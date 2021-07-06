#include "so_long.h"

void	set_player_pos(t_all *all, int x, int y)
{
	all->plr.x = x * SCALE + SCALE / 2.0;
	all->plr.y = y * SCALE + SCALE / 2.0;
}

// void	set_player_dir(t_all *all, double dir)
// {
// 	all->plr.dir = dir;
// }

int	wall_collision(t_all *all, int dir)
{
	// double	dir_x;
	// double	dir_y;
	t_plr	check_dir;
// (void)dir;
	if (dir == UP)
		check_dir = (t_plr){0, 1};
	else if (dir == DOWN)
		check_dir = (t_plr){0, -1};
	else if (dir == LEFT)
		check_dir = (t_plr){-1, 0};
	else if (dir == RIGHT)
		check_dir = (t_plr){1, 0};
	return (all->map
		[(int)(all->plr.y / SCALE - check_dir.y * DIR_COEF)]
		[(int)(all->plr.x / SCALE + check_dir.x * DIR_COEF)]
		== '1');
}

// int	wall_collision_x(t_all *all, double dir)
// {
// 	return (all->map
// 		[(int)floor(all->plr.y / SCALE - sin(all->plr.dir + dir) * COLL)]
// 		[(int)floor(all->plr.x / SCALE + cos(all->plr.dir + dir) * COLL)]
// 		== '1');
// }

void	count_movements(t_all *all, double movement)
{
	all->moves_buffer += movement;
	if (all->moves_buffer >= SCALE)
	{
		all->moves_counter++;
		all->moves_buffer -= SCALE;
		printf("%d move\n", all->moves_counter);
	}
}

void	move_player(t_all *all, int dir)
{
	// double	movement;

	// movement = 0.0;
	if (!wall_collision(all, dir))
	{
		count_movements(all, all->movement);
		if (dir == UP)
			all->plr.y -= all->movement;
		else if (dir == DOWN)
			all->plr.y += all->movement;
		else if (dir == LEFT)
			all->plr.x -= all->movement;
		else if (dir == RIGHT)
			all->plr.x += all->movement;
		// all->movement = cos(all->plr.dir + dir) * MOVE_SPEED * SCALE;
		// printf("%f cos\n", all->movement);
		// all->plr.x += all->movement;
		
	}
	// if (!wall_collision(all, dir))
	// {
	// 	all->movement = sin(all->plr.dir + dir) * MOVE_SPEED * SCALE;
	// 	// printf("%f sin\n", sin(all->plr.dir + dir));
	// 	all->plr.y -= all->movement;
	// 	count_movements(all, all->movement);
	// }
}

// void	move_player(t_all *all, double dir)
// {
// 	// double	movement;

// 	// movement = 0.0;
// 	if (!wall_collision(all, dir))
// 	{
// 		all->movement = cos(all->plr.dir + dir) * MOVE_SPEED * SCALE;
// 		// printf("%f cos\n", all->movement);
// 		all->plr.x += all->movement;
// 		count_movements(all, all->movement);
// 	}
// 	if (!wall_collision(all, dir))
// 	{
// 		all->movement = sin(all->plr.dir + dir) * MOVE_SPEED * SCALE;
// 		// printf("%f sin\n", sin(all->plr.dir + dir));
// 		all->plr.y -= all->movement;
// 		count_movements(all, all->movement);
// 	}
// }
