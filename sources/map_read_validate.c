/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:44:09 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 06:45:05 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Map validation error message (written on stderr)
*/

void	val_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit (1);
}

/*
** Handles the test battery to check if the map is valid, 
** throwing the respective error message in case of failure. 
*/

void	validate_map(char **map)
{	
	if (map_rectangle_check(map) == 1)
		val_error("Error\nmap is not a rectangle.\n");
	else if (map_wall_check(map) == 1)
		val_error("Error\nmap isn't surrounded by walls.\n");
	else if (map_char_check(map) == 1)
		val_error("Error\nmap has an invalid type or number of characters.\n");
	else if (map_path_check(map) == 1)
		val_error("Error\nmap has no valid path between player and exit.\n");
	else if (map_size_check(map) == 1)
		val_error("Error\nmap exceeds the maximum window size.\n");
}

char	**read_map(char *arg)
{
	int		map_file;
	char	*map_string;
	char	*temp;
	char	**map_for_validation;
	char	**map_final;

	map_file = open(arg, O_RDONLY);
	if (map_file == -1)
	{
		perror("Error");
		exit (1);
	}
	temp = ft_calloc(1, 1);
	map_string = ft_calloc(1, 1);
	while (read(map_file, temp, 1) != 0)
		map_string = strjoin_gnl(map_string, temp);
	if (!map_string[0])
		exit(1);
	map_for_validation = ft_split(map_string, '\n');
	map_final = ft_split(map_string, '\n');
	free(map_string);
	free(temp);
	validate_map(map_for_validation);
	free_split(map_for_validation);
	return (map_final);
}

/*
** Places images on the map according to its contents.
** (Note: Enemies are rendered on a separate function, as they
** are placed randomly, rather than specified by a map character); 
*/

void	render_map(char **map, t_win window)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map[++y])
	{
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				render_image(window, window.player_d, x * 32, y * 32);
			else if (map[y][x] == 'E')
				render_image(window, window.exit, x * 32, y * 32);
			else if (map[y][x] == 'C')
				render_image(window, window.collectible, x * 32, y * 32);
			else if (map[y][x] == '1')
				render_image_walls(window, x, y);
			else if (map[y][x] == '0')
				render_image(window, window.floor, x * 32, y * 32);
		}
		x = -1;
	}
}

void	render_image_walls(t_win window, int x, int y)
{
	if (y == 0 && (x == 0 || x == window.width / 32 - 1))
		render_image(window, window.wall_clear, x * 32, y * 32);
	else if (y == window.height / 32 - 1
		&& (x == window.width / 32 - 1 || x == 0))
		render_image(window, window.wall_clear, x * 32, y * 32);
	else if (y == 0)
		render_image(window, window.wall_top, x * 32, y * 32);
	else if (y == window.height / 32 - 1)
		render_image(window, window.wall_bottom, x * 32, y * 32);
	else if (x == 0)
		render_image(window, window.wall_left, x * 32, y * 32);
	else if (x == window.width / 32 - 1)
		render_image(window, window.wall_right, x * 32, y * 32);
	else
		render_image(window, window.wall_full, x * 32, y * 32);
}
