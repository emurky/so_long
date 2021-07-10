#ifndef STRUCTURES_H
# define STRUCTURES_H 

typedef struct s_int
{
	int			x;
	int			y;
}				t_int;

typedef struct s_dbl
{
	double		x;
	double		y;
}				t_dbl;

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
	t_dbl		tex_k;
}				t_img;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_img		img;

	int			flags[6];
	char		*line;
	t_int		window;
	char		**map;
	t_int		max_map;
	t_dbl		plr;
	int			collectibles;
	t_img		tex[11];

	int			keys[5];
	double		movement;
	int			moves_counter;
	double		moves_buffer;
	int			welcome_counter;
	int			exit_counter;
	int			frames;
}				t_all;

#endif
