#include "so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->linelen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_img *tex, int x, int y)
{
	char	*pixel;

	pixel = tex->addr + (y * tex->linelen + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	my_mlx_tex_to_image(t_all *all, t_img *tex, char *path)
{
	// tex->img = NULL;
	// tex->addr = NULL;
	tex->img
		= mlx_xpm_file_to_image(all->mlx, path, &tex->w, &tex->h);
	tex->addr
		= mlx_get_data_addr(tex->img, &tex->bpp, &tex->linelen, &tex->endian);
	// free(*path);
	// *path = NULL;
}

void	mlx_start(t_all *all)
{
	all->mlx = mlx_init();
	all->img.img = mlx_new_image(all->mlx, all->window.x, all->window.y);
	all->img.addr = mlx_get_data_addr
		(all->img.img, &all->img.bpp, &all->img.linelen, &all->img.endian);
	all->win = mlx_new_window(all->mlx, all->window.x, all->window.y, "so_long");
}

void	clean_mlx(t_all *all)
{
	int		i;

	i = 0;
	if (all->mlx && all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->mlx && all->img.img)
		mlx_destroy_image(all->mlx, all->img.img);
	// while (i < 5)
	// {
	// 	if (all->mlx && all->tex[i].img)
	// 		mlx_destroy_image(all->mlx, all->tex[i].img);
	// 	i++;
	// }
}
