#include "so_long.h"

void	draw_square(t_img *img, int width, t_pnt pos, int color)
{
	int		i;
	int		j;

	j = pos.y;
	while (j < width + pos.y - GRID)
	{
		i = pos.x;
		while (i < width + pos.x - GRID)
		{
			my_mlx_pixel_put(img, i, j, color);
			i++;
		}
		j++;
	}
}

void	draw_map_sprites(t_all *all, t_pnt *pos)
{
	draw_square(&all->img, SCALE, *pos, WHITE);
	pos->x += (SCALE - SCALE / SPRITE_SCALE) / 2;
	pos->y += (SCALE - SCALE / SPRITE_SCALE) / 2;
	draw_square(&all->img, SCALE / SPRITE_SCALE, *pos, PLUM);
	pos->x -= (SCALE - SCALE / SPRITE_SCALE) / 2;
	pos->y -= (SCALE - SCALE / SPRITE_SCALE) / 2;
}

void	draw_map_squares(t_all *all, char **map)
{
	int		i;
	int		j;
	t_pnt	pos;

	j = 0;
	pos.y = 0;
	while (map[j])
	{
		i = 0;
		pos.x = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				draw_square(&all->img, SCALE, pos, DARK_GREY);
			else if (map[j][i] == 'C')
				draw_map_sprites(all, &pos);
			else if (map[j][i] == '0' || map[j][i] == 'P')
				draw_square(&all->img, SCALE, pos, WHITE);
			else if (map[j][i] == 'E')
				draw_square(&all->img, SCALE, pos, RED);
			pos.x += SCALE;
			i++;
		}
		pos.y += SCALE;
		j++;
	}
}

void	draw_map(t_all *all)
{
	t_pnt	pos;

	pos.x = all->plr.x - SCALE / 2;
	pos.y = all->plr.y - SCALE / 2;
	draw_map_squares(all, all->map);
	draw_square(&all->img, SCALE, pos, AMBER);
	// printf("%f posx %f posy\n", all->plr.x, all->plr.y);
	// cast_rays(all, all->map, RAYCOUNT, SUNRAY);
	// draw_ray(all, all->map, RED);
}
