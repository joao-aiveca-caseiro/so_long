/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:08:32 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/16 21:57:10 by jaiveca-         ###   ########.fr       */
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

typedef struct s_animation
{
	t_img	frame_1;
	t_img	frame_2;
	t_img	frame_3;
	t_img	frame_4;
	t_img	frame_5;
	t_img	frame_6;
	t_img	frame_7;
	t_img	frame_8;
	t_img	frame_9;
	t_img	frame_10;
	t_img	frame_11;
	t_img	frame_12;
	t_img	frame_13;
	t_img	frame_14;
	t_img	frame_15;
	t_img	frame_16;
	t_img	frame_17;
	t_img	frame_18;
	t_img	frame_19;
	t_img	frame_20;
	t_img	frame_21;
	t_img	frame_22;
	t_img	frame_23;
}			t_animation;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			height;
	int			width;
	char		**map;
	int			move_count;
	int			frame_count;
	t_img		player;
	t_img		collectible;
	t_img		exit;
	t_img		enemy;
	t_img		floor;
	t_img		wall_full;
	t_img		wall_left;
	t_img		wall_right;
	t_img		wall_top;
	t_img		wall_bottom;
	t_img		wall_clear;
	t_animation	anim;
}				t_win;

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
char	**spawn_enemies(char **map, int spawned);
t_win	move_enemies(t_win window);
int		map_size_check(char **map);
void	animate_enemies(t_win window, int sprite_nb);
void	free_split(char **split);
t_win	load_animations(t_win window);
int		close_window(t_win *window);
void	render_image_walls(t_win window, int x, int y);


#endif
