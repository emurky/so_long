#include "so_long.h"

void	malloc_map(t_all *all, t_list **head)
{
	int		j;
	t_list	*temp;

	j = 0;
	temp = *head;
	all->map = malloc((all->max_map.y + 1) * sizeof(char *));
	if (!all->map)
		leave(ERR, ERR_MALLOC, all);
	while (temp && j < all->max_map.y)
	{
		all->map[j] = NULL;
		all->map[j] = malloc((all->max_map.x + 1) * sizeof(char));
		if (!all->map[j])
			leave(ERR, ERR_MALLOC, all);
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
		leave(ERR, ERR_MAP_CLSD, all);
	if (!all->flags[PLR])
		leave(ERR, ERR_PLR_NON, all);
	if (!all->flags[EXT])
		leave(ERR, ERR_EXT_NON, all);
	if (!all->collectibles)
		leave(ERR, ERR_COL, all);
	all->flags[EXT] = FALSE;
}

void	get_map_line(t_all *all, t_list **head, int line_read)
{
	int		line_checked;

	line_checked = check_map_line(all, all->line);
	if (all->flags[EOM] && line_read && *all->line)
		leave(ERR, ERR_MAP_LST, all);
	if (line_checked == 1)
		ft_lstadd_back(head, (ft_lstnew(ft_strdup(all->line))));
	else if (line_checked == -1)
		leave(ERR, ERR_MAP_CHR, all);
	else if (line_checked == -2)
		leave(ERR, ERR_NOT_RECT, all);
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
		leave(ERR, ERR_EMPTY, all);
	parse_map(all, fd, line_read);
	check_map(all);
	set_window_size(all);
	close(fd);
}
