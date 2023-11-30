/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 02:58:42 by egumus            #+#    #+#             */
/*   Updated: 2023/11/30 03:27:42 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_write_score(t_state *state)
{
	char	*score;
	char	*tmp;

	score = ft_itoa(state->player->moves);
	tmp = ft_strjoin("Score: ", score);
	mlx_string_put(state->mlx, state->win, 10, 10, 0x00FF0000, tmp);
	free(score);
	free(tmp);
}

void	ft_redraw_map(t_state *state)
{
	int		x;
	int		y;

	y = 0;
	while (y < state->map->height)
	{
		x = 0;
		while (x < state->map->width)
		{
			if (state->map->board[y][x] == 'P')
				state->map->board[y][x] = '0';
			x++;
		}
		y++;
	}
	state->map->board[state->player->y][state->player->x] = 'P';
}

int	is_next_tile_is(t_state *state, int direction, char tile)
{
	if (direction == RIGHT_DIR)
	{
		if (state->map->board[state->player->y][state->player->x + 1] == tile)
			return (1);
	}
	else if (direction == LEFT_DIR)
	{
		if (state->map->board[state->player->y][state->player->x - 1] == tile)
			return (1);
	}
	else if (direction == DOWN_DIR)
	{
		if (state->map->board[state->player->y + 1][state->player->x] == tile)
			return (1);
	}
	else if (direction == UP_DIR)
	{
		if (state->map->board[state->player->y - 1][state->player->x] == tile)
			return (1);
	}
	return (0);
}

int	check_logic(t_state *state, int direction)
{
	if (is_next_tile_is(state, direction, '1'))
		return (0);
	if (is_next_tile_is(state, direction, 'C'))
		state->collectiables--;
	if (is_next_tile_is(state, direction, 'E') && state->collectiables == 0)
	{
		state->player->moves++;
		ft_printf("You win!\n");
		free_state(state);
		exit(0);
	}
	state->player->moves++;
	return (1);
}

void	player_move(t_state *state, int direction)
{
	if (!check_logic(state, direction))
		return ;
	if (state->player->x == state->exit->x
		&& state->player->y == state->exit->y)
		state->map->board[state->player->y][state->player->x] = 'E';
	else
		state->map->board[state->player->y][state->player->x] = '0';
	if (direction == RIGHT_DIR)
		state->player->x++;
	else if (direction == LEFT_DIR)
		state->player->x--;
	else if (direction == DOWN_DIR)
		state->player->y++;
	else if (direction == UP_DIR)
		state->player->y--;
	state->map->board[state->player->y][state->player->x] = 'P';
}
