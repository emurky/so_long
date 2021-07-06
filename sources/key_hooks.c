#include "so_long.h"

int	close_window(t_all *all)
{
	leave(NO_ERR, NULL, all, NULL);
	return (0);
}

int	key_pressed(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[UP] = true;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[DOWN] = true;
	else if (key == KEY_A || key == KEY_LEFT)
	{
		all->flags[L_DIR] = true;
		all->keys[LEFT] = true;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		all->flags[L_DIR] = false;
		all->keys[RIGHT] = true;
	}
	else if (key == KEY_ESC)
		all->keys[ESC] = true;
	return (0);
}

int	key_released(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[UP] = false;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[DOWN] = false;
	else if (key == KEY_A || key == KEY_LEFT)
		all->keys[LEFT] = false;
	else if (key == KEY_D || key == KEY_RIGHT)
		all->keys[RIGHT] = false;
	else if (key == KEY_ESC)
		all->keys[ESC] = false;
	return (0);
}

void	keys_handler(t_all *all)
{
	if (all->keys[UP])
		move_player(all, UP);
	else if (all->keys[DOWN])
		move_player(all, DOWN);
	else if (all->keys[LEFT])
		move_player(all, LEFT);
	else if (all->keys[RIGHT])
		move_player(all, RIGHT);
	if (all->keys[ESC])
		leave(NO_ERR, NULL, all, NULL);
}
