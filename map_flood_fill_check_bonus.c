/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill_check_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:15:46 by egumus            #+#    #+#             */
/*   Updated: 2023/11/30 00:29:37 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_add_enemy(t_state *state, int x, int y)
{
	t_enemy	*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (enemy == NULL)
		exit_err(1, "Failed to open malloc", state);
	enemy->x = x;
	enemy->y = y;
	enemy->direction = DOWN_DIR;
	enemy->next = state->enemy;
	state->enemy = enemy;
}

void	ft_locate_enemies(t_state *state)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < state->map->height)
	{
		j = 0;
		while (j < state->map->width)
		{
			if (state->map->board[i][j] == 'X')
			{
				ft_add_enemy(state, j, i);
				count++;
			}
			j++;
		}
		i++;
	}
	state->enemy_count = count;
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
	state->player->current_img = 0;
	map_copy = copy_map(state->map, state);
	ft_flood_fill(map_copy, loc[0], loc[1]);
	free(loc);
	check_is_all_accessable(map_copy, state);
	ft_set_exit(state);
	ft_locate_enemies(state);
	free_map(map_copy);
}
