#ifndef STRUCTURES_H
# define STRUCTURES_H 

typedef struct s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef struct s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

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
}				t_img;

typedef struct s_plr
{
	double		x;
	double		y;
	double		dir;
}				t_plr;

typedef struct s_spr
{
	double		x;
	double		y;
	double		dist;
	int			order;
}				t_spr;

typedef struct s_tex
{
	void		*img;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
	int			w;
	int			h;
}				t_tex;

typedef struct s_ray
{
	int			w;
	int			h;
	int			x;
	int			y;
	double		k;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		pln_x;
	double		pln_y;
	double		cam_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_step;
	double		tex_pos;
	int			pixel;
	int			num_sprs;
	double		*z_buff;
	t_spr		*sprites;
	int			s_i;
	double		spr_x;
	double		spr_y;
	double		inv_det;
	double		transf_x;
	double		transf_y;
	int			sprscrn_x;
	int			v_move_scrn;
	int			spr_h;
	int			spr_w;
	int			dr_start_y;
	int			dr_end_y;
	int			dr_start_x;
	int			dr_end_x;
	int			s_tex_x;
	int			s_tex_y;
	int			d;
}				t_ray;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_img		img;

	char		*line;
	t_pnt		window;
	int			flags[4];
	char		**map;
	t_pnt		max_map;

	t_plr		plr;

	int			moves_counter;
	double		moves_buffer;
	int			welcome;
	// t_ray		ray;

	int			keys[5];
}				t_all;

#endif
