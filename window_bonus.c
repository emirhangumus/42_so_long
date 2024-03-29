/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:19:28 by egumus            #+#    #+#             */
/*   Updated: 2023/11/30 03:23:47 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_write_image(t_state *state, int x, int y)
{
	if (state->map->board[y][x] == '1')
		mlx_put_image_to_window(state->mlx, state->win, state->img_paths->img_1,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (state->map->board[y][x] == '0')
		mlx_put_image_to_window(state->mlx, state->win, state->img_paths->img_0,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (state->map->board[y][x] == 'C')
		mlx_put_image_to_window(state->mlx, state->win, state->img_paths->img_c,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (state->map->board[y][x] == 'E')
		mlx_put_image_to_window(state->mlx, state->win, state->img_paths->img_e,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (state->map->board[y][x] == 'P')
	{
		if (state->player->current_img == 0)
			mlx_put_image_to_window(state->mlx, state->win,
				state->img_paths->img_p, x * TILE_SIZE, y * TILE_SIZE);
		else if (state->player->current_img == 1)
			mlx_put_image_to_window(state->mlx, state->win,
				state->img_paths->img_p2, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (state->map->board[y][x] == 'X')
		mlx_put_image_to_window(state->mlx, state->win, state->img_paths->img_x,
			x * TILE_SIZE, y * TILE_SIZE);
}

int	ft_put_images(t_state *state)
{
	int		x;
	int		y;

	y = 0;
	while (y < state->map->height)
	{
		x = 0;
		while (x < state->map->width)
		{
			ft_write_image(state, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_init_images(t_state *state)
{
	int	i;
	int	j;

	state->img_paths = malloc(sizeof(void *) * 7);
	if (state->img_paths == NULL)
		exit_err(1, "Failed to open malloc", state);
	state->img_paths->img_0 = mlx_xpm_file_to_image(state->mlx,
			"./textures/empty.xpm", &i, &j);
	state->img_paths->img_1 = mlx_xpm_file_to_image(state->mlx,
			"./textures/wall.xpm", &i, &j);
	state->img_paths->img_c = mlx_xpm_file_to_image(state->mlx,
			"./textures/collectiable.xpm", &i, &j);
	state->img_paths->img_e = mlx_xpm_file_to_image(state->mlx,
			"./textures/exit.xpm", &i, &j);
	state->img_paths->img_p = mlx_xpm_file_to_image(state->mlx,
			"./textures/a_player0.xpm", &i, &j);
	state->img_paths->img_p2 = mlx_xpm_file_to_image(state->mlx,
			"./textures/a_player1.xpm", &i, &j);
	state->img_paths->img_x = mlx_xpm_file_to_image(state->mlx,
			"./textures/enemy.xpm", &i, &j);
}

void	ft_window(t_state *state)
{
	state->mlx = mlx_init();
	state->win = mlx_new_window(state->mlx, state->map->width * TILE_SIZE,
			state->map->height * TILE_SIZE, "so_long");
	ft_init_images(state);
	ft_put_images(state);
	mlx_key_hook(state->win, ft_key_hook, state);
	mlx_hook(state->win, 17, 0, ft_close, state);
	mlx_loop_hook(state->mlx, ft_loop_hook, state);
	ft_write_score(state);
	mlx_loop(state->mlx);
}
