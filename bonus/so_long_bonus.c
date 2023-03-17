/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 07:06:56 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
** Initializes a new mlx instance and starts a window with 
** the predetermined size, storing the respective pointers 
** in the main structure. Also loads all needed tile images. 
*/

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

/*
** Listens to the keys pressed, if WASD then player movement 
** is triggered, if ESC both the window and program close. 
*/

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

/*
** Checks if the supplied argument ends with ".ber".
*/

int	map_extension_check(char *arg)
{
	char	*substr;

	substr = ft_substr(arg, ft_strlen(arg) - 4, 4);
	if (ft_strncmp(substr, ".ber", 5) == 0)
	{
		free(substr);
		return (0);
	}
	free(substr);
	return (1);
}

void	arg_error(void)
{
	write(2, "Error: Please provide, as a single argument, \
the path to a .ber file.\n", 70);
	exit (1);
}

/*
** If the number of arguments is correct, does the following,
** triggering functions as needed:
** - Opens the map (validation is done if the opening is successful);
** - Gathers the map size (in tiles, or chars);
** - Starts the program with a window size based on the above step;
** - Spawns enemies randomly on the map;
** - Renders the map tiles, including the enemies spawned above;
** - Starts the frame count (used to time the animations);
** - Loads the enemy animations;
** - Starts hooks to listen to pressed keys, clicks 
*/

int	main(int argc, char **argv)
{
	t_win	so_long;
	t_size	map_size;
	char	**map;

	so_long.map = NULL;
	map_size.width = 0;
	if (argc == 2 && map_extension_check(argv[1]) == 0)
	{
		map = read_map(argv[1]);
		map_size = map_size_tiles(map, map_size);
		so_long = new_program(map_size.width * 32, \
			map_size.height * 32, "So Long");
		so_long.map = spawn_enemies(map, 0);
		render_map(so_long.map, so_long);
		so_long.frame_count = 0;
		so_long = load_animations(so_long);
	}
	else
		arg_error();
	mlx_hook(so_long.win_ptr, 17, 0, close_window, &so_long);
	mlx_hook(so_long.win_ptr, 2, 1L << 0, key_press, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, animate_loop, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
