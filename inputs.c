/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:24:18 by egumus            #+#    #+#             */
/*   Updated: 2023/11/28 05:23:59 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_state *state)
{
	if (keycode == KEY_ESC)
	{
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
	ft_put_images(state);
	return (0);
}
