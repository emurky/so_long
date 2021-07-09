#include "so_long_bonus.h"

void	witcher_signs(t_all *all, int flag)
{
	if (!flag)
	{
		sign_background(all, 264, LEAFY_GREEN);
		mlx_string_put(all->mlx, all->win,
			all->window.x / 2 - 123, all->window.y / 2,
			DARK_BROWN, "You LOST! You've met your destiny...");
	}
	else
	{
		if (all->window.y >= 30 && all->window.x >= 265 && all->flags[EXT])
		{
			sign_background(all, 264, LEAFY_GREEN);
			mlx_string_put(all->mlx, all->win,
				all->window.x / 2 - 123, all->window.y / 2,
				DARK_BROWN, "You WON! You've found your destiny!");
			all->exit_counter--;
			if (!all->exit_counter && all->flags[EXT])
				close_window(all);
		}
		else if (all->flags[EXT])
			close_window(all);
	}
}

void	witcher_textures_init(t_all *all)
{
	my_mlx_tex_to_image(all, &all->tex[WATER], "textures/witcher/grass.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_L], "textures/witcher/wtr_L.xpm");
	my_mlx_tex_to_image(all, &all->tex[DOLPH_R], "textures/witcher/wtr_R.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH1], "textures/witcher/monster1.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH2], "textures/witcher/monster2.xpm");
	my_mlx_tex_to_image(all, &all->tex[FISH3], "textures/witcher/monster3.xpm");
	my_mlx_tex_to_image(all, &all->tex[WEED], "textures/witcher/tree.xpm");
	my_mlx_tex_to_image(all, &all->tex[EXIT], "textures/witcher/ciri.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE1], "textures/witcher/death1.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE2], "textures/witcher/death2.xpm");
	my_mlx_tex_to_image(all, &all->tex[MINE3], "textures/witcher/death3.xpm");
}
