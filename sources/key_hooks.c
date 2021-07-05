#include "so_long.h"

int	print_key(int key, t_all *all)
{
	(void)all;
	printf("%d was pressed\n", key);
	return (0);
}

int	close_window(t_all *all)
{
	leave(NO_ERR, NULL, all, NULL);
	return (0);
}

int	key_pressed(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[0] = true;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[1] = true;
	else if (key == KEY_A || key == KEY_LEFT)
		all->keys[2] = true;
	else if (key == KEY_D || key == KEY_RIGHT)
		all->keys[3] = true;
	else if (key == KEY_ESC)
		all->keys[4] = true;
	return (0);
}

int	key_released(int key, t_all *all)
{
	if (key == KEY_W || key == KEY_UP)
		all->keys[0] = false;
	else if (key == KEY_S || key == KEY_DOWN)
		all->keys[1] = false;
	else if (key == KEY_A || key == KEY_LEFT)
		all->keys[2] = false;
	else if (key == KEY_D || key == KEY_RIGHT)
		all->keys[3] = false;
	else if (key == KEY_ESC)
		all->keys[4] = false;
	return (0);
}

void	keys_handler(t_all *all)
{
	if (all->keys[0])
		move_player(all, 0);
	else if (all->keys[1])
		move_player(all, M_PI);
	else if (all->keys[2])
		move_player(all, M_PI_2);
	else if (all->keys[3])
		move_player(all, -M_PI_2);
	if (all->keys[4])
	{ 	printf("%d colls\n", all->collectibles);
		leave(NO_ERR, NULL, all, NULL);}
}
