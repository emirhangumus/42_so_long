/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:47:27 by egumus            #+#    #+#             */
/*   Updated: 2023/11/28 04:01:48 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_file_ext_valid(char *path, t_state *state)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		exit_err(3, "File extension is not valid.", state);
	if (ft_strncmp(path + len - 4, ".ber", 4) != 0)
		exit_err(3, "File extension is not valid.", state);
}

void	ft_check_map(t_state *state)
{
	int	fd;

	if (!state->map_path)
		exit_err(2, "Map path is not set.", state);
	ft_is_file_ext_valid(state->map_path, state);
	fd = open(state->map_path, O_RDONLY);
	if (fd == -1)
		exit_err(7, "Failed to open file.", state);
	map_border_checker(state, fd);
	map_objective_checker(state);
	map_flood_fill_checker(state);
}
