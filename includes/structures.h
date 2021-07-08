#ifndef STRUCTURES_H
# define STRUCTURES_H 

typedef struct s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}				t_map;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct s_plr
{
	double		x;
	double		y;
}				t_plr;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			flags[5];
	char		*line;
	t_pnt		window;
	char		**map;
	t_pnt		max_map;
	t_plr		plr;
	int			collectibles;
	t_img		tex[11];
	double		tex_k;

	int			keys[5];
	double		movement;
	double		move_speed;
	int			moves_counter;
	double		moves_buffer;
	int			welcome_counter;
	int			exit_counter;
	int			frames;
}				t_all;

#endif
