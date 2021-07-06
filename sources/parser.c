#include "so_long.h"

int	isvalid_extension(char *file, const char *ext)
{
	int		ext_len;
	int		file_len;

	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (ft_strncmp(file + file_len - ext_len, ext, ext_len + 1))
		return (false);
	return (true);
}

void	malloc_map(t_all *all, t_list **head)
{
	int		j;
	t_list	*temp;

	j = 0;
	temp = *head;
	all->map = malloc((all->max_map.y + 1) * sizeof(char *));
	if (!all->map)
		leave(ERR, ERR_MALLOC, all, NULL);
	while (temp && j < all->max_map.y)
	{
		all->map[j] = NULL;
		all->map[j] = malloc((all->max_map.x + 1) * sizeof(char));
		if (!all->map[j])
			leave(ERR, ERR_MALLOC, all, NULL);
		all->map[j][all->max_map.x] = '\0';
		ft_memmove(all->map[j], temp->content, ft_strlen(temp->content));
		temp = temp->next;
		j++;
	}
	all->map[j] = NULL;
}

void	check_map(t_all *all)
{
	t_map	map;

	map = (t_map){all->map, all->max_map.x, all->max_map.y};
	set_map_chars(all, all->map);
	if (!check_continuity(map))
		leave(ERR, ERR_MAP_CLSD, all, NULL);
	if (!all->flags[PLR])
		leave(ERR, ERR_PLR_NON, all, NULL);
	if (!all->flags[EXT])
		leave(ERR, ERR_EXT_NON, all, NULL);
	if (!all->collectibles)
		leave(ERR, ERR_COL, all, NULL);
	all->window.x = all->max_map.x * SCALE;
	all->window.y = all->max_map.y * SCALE;
	all->flags[EXT] = false;
}

void	get_map_line(t_all *all, t_list **head, int line_read)
{
	int		line_checked;

	line_checked = check_map_line(all, all->line);
	if (all->flags[EOM] && line_read && *all->line)
		leave(ERR, ERR_MAP_LST, all, NULL);
	if (line_checked == 1)
		ft_lstadd_back(head, (ft_lstnew(ft_strdup(all->line))));
	else if (line_checked == -1)
		leave(ERR, ERR_MAP_CHR, all, NULL);
	else if (line_checked == -2)
		leave(ERR, ERR_NOT_RECT, all, NULL);
	free(all->line);
	all->line = NULL;
}

void	parse_map(t_all *all, int fd, int line_read)
{
	t_list	*head;

	head = NULL;
	while (line_read && !ft_strncmp(all->line, "", 1))
	{
		free(all->line);
		all->line = NULL;
		line_read = get_next_line(fd, &all->line);
	}
	all->max_map.x = ft_strlen(all->line);
	while (line_read)
	{
		get_map_line(all, &head, line_read);
		line_read = get_next_line(fd, &all->line);
	}
	get_map_line(all, &head, line_read);
	all->max_map.y = ft_lstsize(head);
	malloc_map(all, &head);
	ft_lstclear(&head);
}

void	parser(t_all *all, char *file_cub)
{
	int		fd;
	int		line_read;

	fd = open(file_cub, O_RDWR);
	if (fd < 0)
		print_error_exit("Cannot open map file\n");
	line_read = get_next_line(fd, &all->line);
	if (!line_read)
		leave(ERR, ERR_EMPTY, all, NULL);
	parse_map(all, fd, line_read);
	check_map(all);
	set_window_size(all);
	// my_mlx_tex_to_image(all, &all->tex, "textures/sea_tile.xpm");
	close(fd);
}
