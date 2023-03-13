/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/13 20:14:09 by jaiveca-         ###   ########.fr       */
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
//	new_program.map = NULL;
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

t_img	new_img(int width, int height, t_win window)
{
	t_img	image;

//	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	image.w = width;
	image.h = height;
	return (image);
}

t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

//	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &(image.w), &(image.h));
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	return (image);
}

// void	put_pixel_img(t_img img, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
// 	{
// 		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
// 		*(unsigned int *) dst = color;
// 	}
// }

int	exit_tutorial(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (0);
}

t_win	player_move(char dir, t_win window)
{
	t_map	coords;

	coords.collect = 0;
	coords = coords_player_exit(window.map, coords);
	window = move_enemies(window);
	if (dir == 'r' && (window.map[coords.player_y][coords.player_x + 1] != '1'))
	{
		ft_printf("Number of moves: %i\n", window.move_count);
		if (window.map[coords.player_y][coords.player_x + 1] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y][coords.player_x + 1] == 'N')
			trigger_defeat();
		render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player, coords.player_x * 32 + 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y][coords.player_x + 1] = 'P';
		window.move_count = window.move_count + 1;
	}
	else if (dir == 'l' && (window.map[coords.player_y][coords.player_x - 1] != '1'))
	{
		ft_printf("Number of moves: %i\n", window.move_count);
		if (window.map[coords.player_y][coords.player_x - 1] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y][coords.player_x - 1] == 'N')
			trigger_defeat();
		render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player, coords.player_x * 32 - 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y][coords.player_x - 1] = 'P';
		window.move_count = window.move_count + 1;
	}
	else if (dir == 'd' && (window.map[coords.player_y + 1][coords.player_x] != '1'))
	{
		ft_printf("Number of moves: %i\n", window.move_count);
		if (window.map[coords.player_y + 1][coords.player_x] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y + 1][coords.player_x] == 'N')
			trigger_defeat();
		render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player, coords.player_x * 32, coords.player_y * 32 + 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y + 1][coords.player_x] = 'P';
		window.move_count = window.move_count + 1;
	}
	else if (dir == 'u' && (window.map[coords.player_y - 1][coords.player_x] != '1'))
	{
		ft_printf("Number of moves: %i\n", window.move_count);
		if (window.map[coords.player_y - 1][coords.player_x] == 'E' && collectible_count(window) == 0)
			trigger_victory();
		if (window.map[coords.player_y - 1][coords.player_x] == 'N')
			trigger_defeat();
		render_image(window, window.floor, coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player, coords.player_x * 32, coords.player_y * 32 - 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y - 1][coords.player_x] = 'P';
		window.move_count = window.move_count + 1;
	}
	ft_printf("there are %i collectibles in the map\n", collectible_count(window));
	return (window);
}

int	key_press(int keycode, t_win *window)
{
	if (keycode == 65307)
		exit_tutorial(window);
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
	}
	mlx_hook(so_long.win_ptr, 17, 0, exit_tutorial, &so_long);
	mlx_hook(so_long.win_ptr, 2, 1L << 0, key_press, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
