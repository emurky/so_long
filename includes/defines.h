#ifndef DEFINES_H
# define DEFINES_H

// # define EOM			0			/* end of map */
// # define PLR			1
// # define EXT			2

enum	e_directions	{UP, DOWN, LEFT, RIGHT, ESC};
enum	e_flags			{EOM, PLR, EXT, L_DIR};
enum	e_textures		{WATER, WEED, DOLPH_L, DOLPH_R, FISH, EXIT};
// # define COL			3

# define MOVE_SPEED		0.042
# define SPEED_COEF		5000000.0

# define GRID			false
# define SCALE			84

# define TEX_RES		128

# define DIR_COEF		0.51

# define SPRITE_SCALE	2



# define EAT_RAD		0.0
# define COLL			0.51

// #define M_PI_2 1.57079632679

#endif
