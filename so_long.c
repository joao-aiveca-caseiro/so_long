/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/16 18:08:36 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int width, int height, char *name)
{
	void	*mlx_ptr;
	t_win	new_program;

	mlx_ptr = mlx_init();
	new_program.mlx_ptr = mlx_ptr;
	new_program.win_ptr = mlx_new_window(mlx_ptr, width, height, name);
	new_program.width = width;
	new_program.height = height;
	new_program.move_count = 0;
	new_program = load_images(new_program);
	return (new_program);
}

t_size	map_size_tiles(char **map, t_size map_size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
			x++;
		y++;
	}
	map_size.width = x;
	map_size.height = y;
	return (map_size);
}

int	close_window(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (0);
}

t_win	player_move(char dir, t_win window)
{
	t_map	coords;
	char	*move_count;
	char	*move_count_string;

	coords.collect = 0;
	coords = coords_player_exit(window.map, coords);
	window = move_enemies(window);
	render_image(window, window.wall_top, 32, 0);
	render_image(window, window.wall_top, 64, 0);
	if (dir == 'r' && (window.map[coords.player_y][coords.player_x + 1] != '1'))
	{
		if (window.map[coords.player_y][coords.player_x + 1] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y][coords.player_x + 1] == 'N')
			trigger_defeat();
		if (window.map[coords.player_y][coords.player_x + 1] != 'E')
		{
			render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
			render_image(window, window.player, coords.player_x * 32 + 32, coords.player_y * 32);
			window.map[coords.player_y][coords.player_x] = '0';
			window.map[coords.player_y][coords.player_x + 1] = 'P';
			window.move_count = window.move_count + 1;
		}
	}
	else if (dir == 'l' && (window.map[coords.player_y][coords.player_x - 1] != '1'))
	{
		if (window.map[coords.player_y][coords.player_x - 1] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y][coords.player_x - 1] == 'N')
			trigger_defeat();
		if (window.map[coords.player_y][coords.player_x - 1] != 'E')
		{
			render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
			render_image(window, window.player, coords.player_x * 32 - 32, coords.player_y * 32);
			window.map[coords.player_y][coords.player_x] = '0';
			window.map[coords.player_y][coords.player_x - 1] = 'P';
			window.move_count = window.move_count + 1;
		}
	}
	else if (dir == 'd' && (window.map[coords.player_y + 1][coords.player_x] != '1'))
	{
		if (window.map[coords.player_y + 1][coords.player_x] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y + 1][coords.player_x] == 'N')
			trigger_defeat();
		if (window.map[coords.player_y + 1][coords.player_x] != 'E')
		{
			render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
			render_image(window, window.player, coords.player_x * 32, coords.player_y * 32 + 32);
			window.map[coords.player_y][coords.player_x] = '0';
			window.map[coords.player_y + 1][coords.player_x] = 'P';
			window.move_count = window.move_count + 1;
		}
	}
	else if (dir == 'u' && (window.map[coords.player_y - 1][coords.player_x] != '1'))
	{
		if (window.map[coords.player_y - 1][coords.player_x] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y - 1][coords.player_x] == 'N')
			trigger_defeat();
		if (window.map[coords.player_y - 1][coords.player_x] != 'E')
		{
			render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
			render_image(window, window.player, coords.player_x * 32, coords.player_y * 32 - 32);
			window.map[coords.player_y][coords.player_x] = '0';
			window.map[coords.player_y - 1][coords.player_x] = 'P';
			window.move_count = window.move_count + 1;
		}
	}
	move_count = ft_itoa(window.move_count);
	move_count_string = ft_strjoin("Moves: ", move_count);
	mlx_string_put(window.mlx_ptr, window.win_ptr, 32, 16, 0x00FF00, move_count_string);
	free(move_count);
	free(move_count_string);
	return (window);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (*(++i + split))
		free((*(i + split)));
	free(split);
}

int	key_press(int keycode, t_win *window)
{
	if (keycode == 65307)
		close_window(window);
	if (keycode == 100)
		*window = player_move('r', *window);
	if (keycode == 97)
		*window = player_move('l', *window);
	if (keycode == 119)
		*window = player_move('u', *window);
	if (keycode == 115)
		*window = player_move('d', *window);
	return (0);
}

int	animate_loop(t_win *window)
{
	static int	fc_threshold;
	static int	sprite_nb;

	if (fc_threshold == 0)
		fc_threshold = 10000;
	if (sprite_nb == 0)
		sprite_nb = 1;
	window->frame_count++;
	if (window->frame_count == fc_threshold)
	{
		animate_enemies(*window, sprite_nb);
		fc_threshold = fc_threshold + 10000;
		sprite_nb++;
	}
	if (window->frame_count == 240000)
	{
		fc_threshold = 10000;
		window->frame_count = 0;
		sprite_nb = 1;
	}
	return(0);
}

int	main(int argc, char **argv)
{
	t_win	so_long;
	t_size	map_size;

	char	**map;

	so_long.map = NULL;
	map_size.width = 0;
	if (argc == 2)
	{
		map = read_map(argv[1]);
		map_size = map_size_tiles(map, map_size);
		so_long = new_program(map_size.width * 32, map_size.height * 32, "So Long");
		so_long.map = spawn_enemies(map);
		render_map(so_long.map, so_long);
		so_long.frame_count = 0;
		so_long = load_animations(so_long);
	}
	mlx_hook(so_long.win_ptr, 17, 0, close_window, &so_long);
	mlx_hook(so_long.win_ptr, 2, 1L << 0, key_press, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, animate_loop, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
