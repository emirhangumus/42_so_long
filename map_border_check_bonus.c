/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:51:08 by egumus            #+#    #+#             */
/*   Updated: 2023/12/06 18:08:41 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_board(t_state *state)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(state->map_path, O_RDONLY);
	if (fd == -1)
		exit_err(7, "Filed to open file.", state);
	i = 0;
	while (i < state->map->height)
	{
		line = get_next_line(fd);
		if (line == NULL)
			exit_err(7, "Map is not valid.", state);
		ft_strlcpy(state->map->board[i], line, state->map->width + 1);
		free(line);
		i++;
	}
	close(fd);
}

static void	map_check_init(t_state *state, int h, int w)
{
	t_map	*map;

	map = ft_create_map(w, h, state);
	state->map = map;
	fill_board(state);
}

static void	check_borders(char *line, int h, int w)
{
	if (h == 1 && !is_full_of(line, w, '1'))
	{
		free(line);
		exit_err(4, "First layer is not full of '1'.", NULL);
	}
	if (line[0] != '1' || line[w - 1] != '1')
	{
		free(line);
		exit_err(5, "Borders are not full of '1'.", NULL);
	}
	if (w != (int)(ft_strlen(line) - 1) && line[w] != '\0')
	{
		free(line);
		exit_err(6, "Not a rectangle!!!", NULL);
	}
}

void	map_border_checker(t_state *state, int fd)
{
	char	*line;
	char	*tmp;
	size_t	h;
	size_t	w;

	line = get_next_line(fd);
	if (line == NULL || (int)ft_strlen(line) == 0)
		exit_err(4, "Width is zero.", state);
	w = ft_strlen(line) - 1;
	h = 0;
	while (line != NULL)
	{
		h++;
		tmp = line;
		check_borders(line, h, w);
		line = get_next_line(fd);
		if (line == NULL && !is_full_of(tmp, w, '1'))
			exit_err(7, "Last layer is not full of '1'.", state);
		free(tmp);
	}
	close(fd);
	map_check_init(state, h, w);
}
