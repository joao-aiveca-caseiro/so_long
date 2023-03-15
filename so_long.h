/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:32 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/14 23:05:26 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <time.h>

typedef struct s_img
{
//	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_size
{
	int	width;
	int	height;
}		t_size;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	char	**map;
	int		move_count;
	t_img	player;
	t_img	collectible;
	t_img	exit;
	t_img	enemy;
	t_img	floor;
	t_img	wall;
}			t_win;

typedef struct s_map
{
	int	player;
	int	exit;
	int	collect;
	int	illegal;
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
}		t_map;


t_map	coords_player_exit(char **map, t_map coords);
char	**map_flood_fill(char **map, int x, int y);
int		map_path_check(char **map);
int		map_rectangle_check(char **map);
int		map_wall_check(char **map);
int		map_char_check(char **map);
void	val_error(char *msg);
void	validate_map(char **map);
char	**read_map(char *arg);
void	render_map(char **map, t_win window);
void	render_image(t_win window, t_img image, int x, int y);
t_img	new_file_img(char *path, t_win window);
t_win	load_images(t_win window);
int		collectible_count(t_win	window);
void	trigger_victory(void);
void	trigger_defeat(void);
char	**spawn_enemies(char **map);
t_win	move_enemies(t_win window);
int		map_size_check(char **map);

#endif
