#include "so_long.h"

int	close_window(t_all *all)
{
	leave(NO_ERR, NULL, all);
	return (0);
}

int	key_pressed(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[UP] = TRUE;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[DOWN] = TRUE;
	else if (key == KEY_A || key == KEY_LEFT)
	{
		all->flags[L_DIR] = TRUE;
		all->keys[LEFT] = TRUE;
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		all->flags[L_DIR] = FALSE;
		all->keys[RIGHT] = TRUE;
	}
	else if (key == KEY_ESC)
		all->keys[ESC] = TRUE;
	return (0);
}

int	key_released(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[UP] = FALSE;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[DOWN] = FALSE;
	else if (key == KEY_A || key == KEY_LEFT)
		all->keys[LEFT] = FALSE;
	else if (key == KEY_D || key == KEY_RIGHT)
		all->keys[RIGHT] = FALSE;
	else if (key == KEY_ESC)
		all->keys[ESC] = FALSE;
	return (0);
}

void	keys_handler(t_all *all)
{
	if (all->keys[UP] || all->keys[DOWN])
	{
		if (all->keys[UP])
			move_player(all, UP);
		if (all->keys[DOWN])
			move_player(all, DOWN);
	}
	else if (all->keys[LEFT] || all->keys[RIGHT])
	{
		if (all->keys[LEFT])
			move_player(all, LEFT);
		if (all->keys[RIGHT])
			move_player(all, RIGHT);
	}
	if (all->keys[ESC])
		leave(NO_ERR, NULL, all);
}
