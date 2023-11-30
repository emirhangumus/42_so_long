/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:15:46 by egumus            #+#    #+#             */
/*   Updated: 2023/11/28 05:13:51 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_exit(t_state *state)
{
	int		*loc;
	t_exit	*exit;

	exit = malloc(sizeof(t_exit));
	if (exit == NULL)
		exit_err(1, "Failed to open malloc", state);
	loc = ft_locate(state, 'E');
	exit->x = loc[1];
	exit->y = loc[0];
	state->exit = exit;
	free(loc);
}

void	check_is_all_accessable(t_map *map, t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->board[i][j] != '1' && map->board[i][j] != '0'
				&& map->board[i][j] != 'E')
			{
				free_map(map);
				exit_err(1, "Cannot reachable all", state);
			}
			j++;
		}
		i++;
	}
}

void	ft_flood_fill(t_map *map, int x, int y)
{
	if (map->board[x][y] != '1')
	{
		map->board[x][y] = '1';
		ft_flood_fill(map, x + 1, y);
		ft_flood_fill(map, x, y + 1);
		ft_flood_fill(map, x - 1, y);
		ft_flood_fill(map, x, y - 1);
	}
}

void	map_flood_fill_checker(t_state *state)
{
	int			*loc;
	t_map		*map_copy;
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		exit_err(1, "Failed to open malloc", state);
	state->player = player;
	loc = ft_locate(state, 'P');
	state->player->x = loc[1];
	state->player->y = loc[0];
	state->player->moves = 0;
	map_copy = copy_map(state->map, state);
	ft_flood_fill(map_copy, loc[0], loc[1]);
	free(loc);
	check_is_all_accessable(map_copy, state);
	ft_set_exit(state);
	free_map(map_copy);
}
