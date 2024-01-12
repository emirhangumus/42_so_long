/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:29:26 by egumus            #+#    #+#             */
/*   Updated: 2023/11/30 03:03:48 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	remove_enemies_from_map(t_state *state)
{
	int	i;
	int	j;

	i = 0;
	while (i < state->map->height)
	{
		j = 0;
		while (j < state->map->width)
		{
			if (state->map->board[i][j] == 'X')
				state->map->board[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	apply_enemy_to_map(t_state *state)
{
	t_enemy	*enemy;

	enemy = state->enemy;
	remove_enemies_from_map(state);
	while (enemy)
	{
		state->map->board[enemy->y][enemy->x] = 'X';
		enemy = enemy->next;
	}
}

void	enemy_move(t_state *state, t_enemy *enemy, int x, int y)
{
	if (state->map->board[y][x] == '1' || state->map->board[y][x] == 'C'
		|| state->map->board[y][x] == 'E' || state->map->board[y][x] == 'X')
	{
		if (enemy->direction == RIGHT_DIR)
			enemy->direction = UP_DIR;
		else if (enemy->direction == LEFT_DIR)
			enemy->direction = DOWN_DIR;
		else if (enemy->direction == DOWN_DIR)
			enemy->direction = RIGHT_DIR;
		else if (enemy->direction == UP_DIR)
			enemy->direction = LEFT_DIR;
	}
	else
	{
		enemy->x = x;
		enemy->y = y;
	}
	apply_enemy_to_map(state);
}

void	move_enemies_directed(t_state *state, t_enemy *enemy)
{
	if (enemy->direction == RIGHT_DIR)
	{
		enemy->direction = UP_DIR;
		enemy_move(state, enemy, enemy->x, enemy->y + 1);
	}
	else if (enemy->direction == LEFT_DIR)
	{
		enemy->direction = DOWN_DIR;
		enemy_move(state, enemy, enemy->x, enemy->y - 1);
	}
	else if (enemy->direction == DOWN_DIR)
	{
		enemy->direction = RIGHT_DIR;
		enemy_move(state, enemy, enemy->x - 1, enemy->y);
	}
	else if (enemy->direction == UP_DIR)
	{
		enemy->direction = LEFT_DIR;
		enemy_move(state, enemy, enemy->x + 1, enemy->y);
	}
}

void	move_enemies(t_state *state, int change_direction)
{
	t_enemy	*enemy;

	enemy = state->enemy;
	while (enemy)
	{
		if (change_direction == 0)
		{
			if (enemy->direction == RIGHT_DIR)
				enemy_move(state, enemy, enemy->x + 1, enemy->y);
			else if (enemy->direction == LEFT_DIR)
				enemy_move(state, enemy, enemy->x - 1, enemy->y);
			else if (enemy->direction == DOWN_DIR)
				enemy_move(state, enemy, enemy->x, enemy->y + 1);
			else if (enemy->direction == UP_DIR)
				enemy_move(state, enemy, enemy->x, enemy->y - 1);
		}
		else
			move_enemies_directed(state, enemy);
		enemy = enemy->next;
	}
}
