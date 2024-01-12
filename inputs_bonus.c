/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:24:18 by egumus            #+#    #+#             */
/*   Updated: 2023/12/06 18:11:16 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_enemy_collision(t_state *state)
{
	t_enemy	*enemy;

	enemy = state->enemy;
	while (enemy)
	{
		if (enemy->x == state->player->x && enemy->y == state->player->y)
		{
			ft_printf("You lost!\n");
			free_state(state);
			exit(0);
		}
		enemy = enemy->next;
	}
}

int	ft_key_hook(int keycode, t_state *state)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(state->mlx, state->win);
		free_state(state);
		exit(0);
	}
	else if (keycode == KEY_D)
		player_move(state, RIGHT_DIR);
	else if (keycode == KEY_S)
		player_move(state, DOWN_DIR);
	else if (keycode == KEY_A)
		player_move(state, LEFT_DIR);
	else if (keycode == KEY_W)
		player_move(state, UP_DIR);
	ft_loop_hook(state);
	return (0);
}

int	ft_loop_hook(t_state *state)
{
	static int	i = 1;
	static int	change_direction = 0;

	if (i % 500 == 0)
		change_direction = 1;
	else
		change_direction = 0;
	if (i % 15 == 0)
		move_enemies(state, change_direction);
	if (i % 30 == 0)
	{
		if (state->player->current_img == 0)
			state->player->current_img = 1;
		else
			state->player->current_img = 0;
	}
	player_enemy_collision(state);
	ft_put_images(state);
	ft_write_score(state);
	i++;
	return (0);
}
