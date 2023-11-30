/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:33:24 by egumus            #+#    #+#             */
/*   Updated: 2023/11/30 03:34:29 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

# define RIGHT_DIR 0
# define LEFT_DIR 1
# define DOWN_DIR 2
# define UP_DIR 3

# define TILE_SIZE 64

typedef struct s_map
{
	int		width;
	int		height;
	char	**board;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
}				t_player;

typedef struct s_exit
{
	int		x;
	int		y;
}				t_exit;

typedef struct s_img
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
}	t_img;

typedef struct s_state
{
	t_map		*map;
	t_player	*player;
	t_exit		*exit;
	t_img		*img_paths;
	char		*map_path;
	int			collectiables;
	void		*mlx;
	void		*win;
}				t_state;

typedef struct s_objects
{
	int		collectiables;
	int		player;
	int		exit;
}				t_objects;

void	exit_err(int err_code, char *err_mess, t_state *state);
void	ft_check_map(t_state *state);
void	map_border_checker(t_state *state, int fd);
void	map_objective_checker(t_state *state);
void	map_flood_fill_checker(t_state *state);

void	ft_window(t_state *state);

void	player_move(t_state *state, int direction);
int		ft_key_hook(int keycode, t_state *state);
int		ft_put_images(t_state *state);

int		is_full_of(char *str, int len, char c);
int		count_len_of(char *str, char c);
t_map	*ft_create_map(int w, int h, t_state *state);
t_map	*copy_map(t_map *map, t_state *state);
int		is_valid_row(char *str);
int		ft_close(t_state *state);

int		*ft_locate(t_state *state, char c);

void	free_map(t_map *map);
void	free_state(t_state *state);

#endif