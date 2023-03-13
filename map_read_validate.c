/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:44:09 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/13 16:47:48 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	val_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit (1);
}

void	validate_map(char **map)
{
	if (map_rectangle_check(map) == 1)
		val_error("Error: map is not a rectangle.\n");
	else if (map_wall_check(map) == 1)
		val_error("Error: map isn't surrounded by walls.\n");
	else if (map_char_check(map) == 1)
		val_error("Error: map has an invalid type or number of characters.\n");
	else if (map_path_check(map) == 1)
		val_error("Error: map has no valid path between player and exit.\n");
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
		exit (1);
	temp = ft_calloc(1, 1);
	map_string = ft_calloc(1, 1);
	while (read(map_file, temp, 1) != 0)
		map_string = strjoin_gnl(map_string, temp);
	map_for_validation = ft_split(map_string, '\n');
	map_final = ft_split(map_string, '\n');
	free(map_string);
	free(temp);
	validate_map(map_for_validation);
	free(map_for_validation);
	return (map_final);
}

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
				render_image(window, window.player, x * 32, y * 32);
			else if (map[y][x] == 'E')
				render_image(window, window.exit, x * 32, y * 32);
			else if (map[y][x] == 'C')
				render_image(window, window.collectible, x * 32, y * 32);
			else if (map[y][x] == '1')
				render_image(window, window.wall, x * 32, y * 32);
			else if (map[y][x] == '0')
				render_image(window, window.floor, x * 32, y * 32);
			else if (map[y][x] == 'N')
				render_image(window, window.enemy, x * 32, y * 32);
		}
		x = -1;
	}
}
