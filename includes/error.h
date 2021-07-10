#ifndef ERROR_H
# define ERROR_H

# define ERR			TRUE
# define NO_ERR			FALSE

# define ERR_MALLOC		"Memory allocation failed\n"
# define ERR_EMPTY		"Map file is empty\n"
# define ERR_MAP_LST	"Map cannot be separated by empty lines\n"
# define ERR_MAP_CHR	"Invalid chars in the map\n"
# define ERR_MAP_CLSD	"Map must be closed/surrounded by walls\n"
# define ERR_PLR_DBL	"Only one player could exist on the map\n"
# define ERR_PLR_NON	"No player on the map\n"
# define ERR_NOT_RECT	"Map is not rectangular\n"
# define ERR_EXT		"Only one exit could exist on the map\n"
# define ERR_EXT_NON	"There must be at least one exit on the map\n"
# define ERR_COL		"There must be at least one collectible\n"
# define ERR_WIN		"Map is too big and cannot be shown on this screen. \
Please decrease SCALE in \"includes/defines.h\"\n"

#endif
