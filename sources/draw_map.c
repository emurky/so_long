#include "so_long.h"

int	get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

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

void	draw_textured_square(t_all *all, t_img *tex, t_pnt pos)
{
	int		i;
	int		j;
	// (void)pos;
	int pixel;		
	// t_pnt tex_res;
// t_img	*tex = mlx_xpm_file_to_image(all->mlx, "textures/sea_tile.xpm", &tex_res.x, &tex_res.y);
// mlx_put_image_to_window(all->mlx, all->win, tex, 0, 0);
			// all->pixel = my_mlx_pixel_get(all->tex, 1300, 12890);
			// printf("%X color\n", all->pixel);
// my_mlx_tex_to_image(all, &all->tex, "textures/sea_tile.xpm");
	j = pos.y;
	while (j < SCALE + pos.y - GRID)
	{
		i = pos.x;
		while (i < SCALE + pos.x - GRID)
		{
			pixel = my_mlx_pixel_get(tex, (i - pos.x) / all->tex_coef, (j - pos.y) / all->tex_coef);
			// printf("%d i %d j\n", (int)((i - pos.x) / all->tex_coef), (int)((j - pos.y) / all->tex_coef));
			if (!get_t(pixel))
				my_mlx_pixel_put(&all->img, i, j, pixel);
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
			// if (map[j][i] == '1')
			// 	draw_square(&all->img, SCALE, pos, DARK_GREY);
				// draw_textured_square(all, pos);
			if (is_interior(map[j][i]) || map[j][i] == '1')
				// draw_square(&all->img, SCALE, pos, WHITE);
				draw_textured_square(all, &all->tex[WATER], pos);
			if (map[j][i] == '1')
				draw_textured_square(all, &all->tex[WEED], pos);
			if (map[j][i] == 'C')
				// draw_map_sprites(all, &pos);
				draw_textured_square(all, &all->tex[FISH], pos);
			if (map[j][i] == 'E')
				// draw_square(&all->img, SCALE, pos, RED);
				draw_textured_square(all, &all->tex[EXIT], pos);
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
	if (all->flags[L_DIR])
		draw_textured_square(all, &all->tex[DOLPH_L], pos);
	else// if (all->keys[RIGHT])
		draw_textured_square(all, &all->tex[DOLPH_R], pos);
	// draw_square(&all->img, SCALE, pos, AMBER);
	// printf("%f posx %f posy\n", all->plr.x, all->plr.y);
	// cast_rays(all, all->map, RAYCOUNT, SUNRAY);
	// draw_ray(all, all->map, RED);
}
