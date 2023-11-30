/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:23:45 by egumus            #+#    #+#             */
/*   Updated: 2023/11/29 23:13:22 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_state(t_state *state)
{
	state->map_path = NULL;
	state->map = NULL;
	state->player = NULL;
	state->img_paths = NULL;
	state->mlx = NULL;
	state->win = NULL;
	state->exit = NULL;
}

int	main(int ac, char **av)
{
	t_state	*state;
	int		err;

	err = 0;
	if (ac != 2)
		exit_err(1, "You have to pass 2 arguments", NULL);
	state = malloc(sizeof(t_state));
	if (state == NULL)
		exit_err(1, "Failed to open malloc", NULL);
	init_state(state);
	state->map_path = av[1];
	ft_check_map(state);
	ft_window(state);
	return (0);
}
