/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:24:14 by egumus            #+#    #+#             */
/*   Updated: 2023/11/29 23:12:30 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_err(int err_code, char *err_mess, t_state *state)
{
	if (state)
		free_state(state);
	ft_printf("[ERROR] Exited with %d error code: %s\n", err_code, err_mess);
	exit(1);
}
