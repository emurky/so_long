#ifndef ERROR_H
# define ERROR_H

# define ERR				true
# define NO_ERR				false

# define ERR_MALLOC			"Memory allocation failed\n"
# define ERR_NUM_RES_IDS	"Wrong number of resolution identifiers\n"
# define ERR_INV_RES_ARG	"Invalid resolution arguments\n"
# define ERR_INV_RES		"Invalid resolution\n"
# define ERR_SCRNSH_RES		"Resolution for screenshot is too big (16384 max)\n"
# define ERR_NUM_TEX		"Wrong number of texture identifiers\n"
# define ERR_TEX_EXT		"Invalid texture extension (must be .xpm)\n"
# define ERR_TEX_FD			"Incorrect path to the texture\n"
# define ERR_INV_FC			"Invalid color argument\n"
# define ERR_FC				"Wrong color format\n"
# define ERR_FC_RNG			"R G B must be in range from 0 to 255\n"
# define ERR_NL				"Should be no characters on empty line(s)\n"
# define ERR_LINE			"Incorrect identifier line\n"
# define ERR_SPCS			"Spaces on empty line\n"
# define ERR_DBL			"One of identifiers is doubled\n"
# define ERR_EMPTY			"Map file is empty\n"
# define ERR_INV			"Invalid file .cub configuration\n"
# define ERR_MAP_LST		"Map cannot be separated by empty lines\n"
# define ERR_MAP_CHR		"Invalid chars in the map\n"
# define ERR_MAP_CLSD		"Map must be closed/surrounded by walls\n"
# define ERR_PLR_DBL		"Only one player could exist on the map\n"
# define ERR_PLR_NON		"No player on the map\n"
# define ERR_SCRNSH			"Failed to save a screenshot\n"

# define ERR_NOT_RECT		"Map is not rectangular\n"
# define ERR_EXT			"Only one exit could exist on the map\n"
# define ERR_COL			"There must be at least one collectible\n"
# define ERR_EXT_NON		"No exit on the map\n"
# define ERR_WIN			"Map is too big and cannot be shown on this screen\n"

#endif
