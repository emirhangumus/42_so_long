/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:52:01 by egumus            #+#    #+#             */
/*   Updated: 2023/11/29 23:02:19 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->board[i]);
		i++;
	}
	free(map->board);
	free(map);
}

void	free_enemy_list(t_enemy *enemy)
{
	t_enemy	*tmp;

	while (enemy)
	{
		tmp = enemy->next;
		free(enemy);
		enemy = tmp;
	}
}

void	free_state(t_state *state)
{
	if (state->map)
		free_map(state->map);
	if (state->player)
		free(state->player);
	if (state->img_paths)
		free(state->img_paths);
	if (state->exit)
		free(state->exit);
	if (state->enemy)
		free_enemy_list(state->enemy);
	free(state);
}
