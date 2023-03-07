/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/07 19:20:21 by jaiveca-         ###   ########.fr       */
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
	new_program.map = NULL;
	return (new_program);
}

t_img	new_img(int width, int height, t_win window)
{
	t_img	image;

	image.win = window;
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

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &(image.w), &(image.h));
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int	exit_tutorial(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (0);
}

void	player_move(char dir, t_win window)
{
	t_map	coords;

	coords.collect = 0;
	if (coords.player)
	coords = coords_player_exit(window.map, coords);
	ft_printf("player is at (%i, %i)", coords.player_x, coords.player_y);
	if (dir == 'r' && (window.map[coords.player_y][coords.player_x + 1] != '1'))
	{
		render_image(window, "floor", coords.player_x * 32, coords.player_y * 32);
		render_image(window, "player", coords.player_x * 32 + 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y][coords.player_x + 1] = 'P';
	}
	else if (dir == 'l' && (window.map[coords.player_y][coords.player_x - 1] != '1'))
	{
		render_image(window, "floor", coords.player_x * 32, coords.player_y * 32);
		render_image(window, "player", coords.player_x * 32 - 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y][coords.player_x - 1] = 'P';
	}
	else if (dir == 'd' && (window.map[coords.player_y + 1][coords.player_x] != '1'))
	{
		render_image(window, "floor", coords.player_x * 32, coords.player_y * 32);
		render_image(window, "player", coords.player_x * 32, coords.player_y * 32 + 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y + 1][coords.player_x] = 'P';
	}
	else if (dir == 'u' && (window.map[coords.player_y - 1][coords.player_x] != '1'))
	{
		render_image(window, "floor", coords.player_x * 32, coords.player_y * 32);
		render_image(window, "player", coords.player_x * 32, coords.player_y * 32 - 32);
		window.map[coords.player_y][coords.player_x] = '0';
		window.map[coords.player_y - 1][coords.player_x] = 'P';
	}
}

int	key_press(int keycode, t_win *window)
{
	ft_printf("keycode=%i\n", keycode);
	if (keycode == 65307)
		exit_tutorial(window);
	if (keycode == 100)
		player_move('r', *window);
	if (keycode == 97)
		player_move('l', *window);
	if (keycode == 119)
		player_move('u', *window);
	if (keycode == 115)
		player_move('d', *window);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	so_long = new_program(1000, 1000, "So Long");
	if (argc == 2)
		so_long.map = read_map(argv[1], so_long);

	mlx_hook(so_long.win_ptr, 17, 0, exit_tutorial, &so_long);
	mlx_hook(so_long.win_ptr, 2, 1L << 0, key_press, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
