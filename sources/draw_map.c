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

void	draw_textured_square(t_all *all, t_img *tex, t_pnt pos)
{
	int		i;
	int		j;
	int		pixel;

	j = pos.y;
	while (j < SCALE + pos.y - GRID)
	{
		i = pos.x;
		while (i < SCALE + pos.x - GRID)
		{
			pixel = my_mlx_pixel_get
				(tex, (i - pos.x) / all->tex_k,
					(j - pos.y) / all->tex_k);
			if (!is_transparent(pixel))
				my_mlx_pixel_put(&all->img, i, j, pixel);
			i++;
		}
		j++;
	}
}

void	map_chars_switcher(t_all *all, char map_char, t_pnt pos)
{
	if (TEXTURED)
	{
		if (is_interior(map_char) || map_char == '1')
			draw_textured_square(all, &all->tex[WATER], pos);
		if (map_char == '1')
			draw_textured_square(all, &all->tex[WEED], pos);
		if (map_char == 'C')
			draw_textured_square(all, &all->tex[FISH], pos);
		if (map_char == 'E')
			draw_textured_square(all, &all->tex[EXIT], pos);
	}
	else
	{
		if (map_char == '1')
			draw_square(&all->img, SCALE, pos, DARK_GREY);
		else if (map_char == 'C')
			draw_map_sprites(all, &pos);
		else if (map_char == '0' || map_char == 'P')
			draw_square(&all->img, SCALE, pos, WHITE);
		else if (map_char == 'E')
			draw_square(&all->img, SCALE, pos, RED);
	}
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
			map_chars_switcher(all, map[j][i], pos);
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
	if (TEXTURED)
	{
		if (all->flags[L_DIR])
			draw_textured_square(all, &all->tex[DOLPH_L], pos);
		else
			draw_textured_square(all, &all->tex[DOLPH_R], pos);
	}
	else
	{
		draw_square(&all->img, SCALE, pos, AMBER);
	}
}
