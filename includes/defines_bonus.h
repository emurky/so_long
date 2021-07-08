#ifndef DEFINES_BONUS_H
# define DEFINES_BONUS_H

# define TRUE			1
# define FALSE			0

enum	e_directions	{UP, DOWN, LEFT, RIGHT, ESC};
enum	e_flags			{EOM, PLR, EXT, L_DIR, LST};
enum	e_textures1		{WATER, WEED, DOLPH_L, DOLPH_R, FISH1, FISH2, FISH3};
enum	e_textures2		{MINE1 = 7, MINE2, MINE3, EXIT};

# define SCALE			84
# define MOVE_SPEED		0.042
# define TEX_RES		128
# define DIR_K			0.51
# define GRID			FALSE
# define TEXTURED		TRUE
# define COUNTER		TRUE

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
