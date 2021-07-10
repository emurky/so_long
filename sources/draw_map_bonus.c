#include "so_long_bonus.h"

void	draw_textured_square(t_all *all, t_img *tex, t_int pos)
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
				(tex, (i - pos.x) / tex->tex_k.x,
					(j - pos.y) / tex->tex_k.y);
			if (!is_transparent(pixel))
				my_mlx_pixel_put(&all->img, i, j, pixel);
			i++;
		}
		j++;
	}
}

void	draw_mines(t_all *all, t_int pos)
{
	if (all->frames % 42 < 7)
		draw_textured_square(all, &all->tex[MINE1], pos);
	else if (all->frames % 42 < 14)
		draw_textured_square(all, &all->tex[MINE2], pos);
	else if (all->frames % 42 < 21)
		draw_textured_square(all, &all->tex[MINE3], pos);
	else if (all->frames % 42 < 28)
		draw_textured_square(all, &all->tex[MINE3], pos);
	else if (all->frames % 42 < 35)
		draw_textured_square(all, &all->tex[MINE2], pos);
	else if (all->frames % 42 < 42)
		draw_textured_square(all, &all->tex[MINE1], pos);
}

void	map_chars_switcher(t_all *all, char map_char, t_int pos)
{
	if (is_interior(map_char) || map_char == '1')
		draw_textured_square(all, &all->tex[WATER], pos);
	if (map_char == '1')
		draw_textured_square(all, &all->tex[WEED], pos);
	if (map_char == 'C')
	{
		if (all->frames % 42 < 7)
			draw_textured_square(all, &all->tex[FISH1], pos);
		else if (all->frames % 42 < 14)
			draw_textured_square(all, &all->tex[FISH2], pos);
		else if (all->frames % 42 < 21)
			draw_textured_square(all, &all->tex[FISH3], pos);
		else if (all->frames % 42 < 28)
			draw_textured_square(all, &all->tex[FISH3], pos);
		else if (all->frames % 42 < 35)
			draw_textured_square(all, &all->tex[FISH2], pos);
		else if (all->frames % 42 < 42)
			draw_textured_square(all, &all->tex[FISH1], pos);
	}
	if (map_char == 'M')
		draw_mines(all, pos);
	if (map_char == 'E')
		draw_textured_square(all, &all->tex[EXIT], pos);
}

void	draw_map_squares(t_all *all, char **map)
{
	int		i;
	int		j;
	t_int	pos;

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
	t_int	pos;

	pos.x = all->plr.x - SCALE / 2;
	pos.y = all->plr.y - SCALE / 2;
	draw_map_squares(all, all->map);
	if (all->flags[L_DIR])
		draw_textured_square(all, &all->tex[DOLPH_L], pos);
	else
		draw_textured_square(all, &all->tex[DOLPH_R], pos);
}
