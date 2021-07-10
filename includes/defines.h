#ifndef DEFINES_H
# define DEFINES_H

# define TRUE			1
# define FALSE			0

enum	e_directions	{UP, DOWN, LEFT, RIGHT, ESC};
enum	e_flags			{EOM, PLR, EXT, L_DIR};
enum	e_textures		{WATER, WEED, DOLPH_L, DOLPH_R, FISH, EXIT};

# define SCALE			84
# define MOVE_SPEED		0.042
# define DIR_K			0.51
# define GRID			FALSE
# define TEXTURED		TRUE
# define COUNTER		FALSE

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_ESC		53

#endif
