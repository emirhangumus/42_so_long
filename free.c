/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 04:52:01 by egumus            #+#    #+#             */
/*   Updated: 2023/11/28 05:18:50 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	free(state);
}
