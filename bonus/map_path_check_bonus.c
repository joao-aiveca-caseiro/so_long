/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:36:05 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 07:06:47 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
** Finds the player and exit characters' positions. 
*/

t_map	coords_player_exit(char **map, t_map coords)
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
			{
				coords.player_x = x;
				coords.player_y = y;
			}
			else if (map[y][x] == 'E')
			{
				coords.exit_x = x;
				coords.exit_y = y;
			}
		}
		x = -1;
	}
	return (coords);
}

/*
** Using recursion, replaces every "walkable" char of 
** the map with a placeholder character. 
*/

char	**map_flood_fill(char **map, int x, int y)
{
	if (map[y][x])
	{
		if (map[y][x] == '1' || map[y][x] == 'F')
			return (map);
		else if (map[y][x] != 'F')
			map[y][x] = 'F';
		map_flood_fill(map, x + 1, y);
		map_flood_fill(map, x - 1, y);
		map_flood_fill(map, x, y + 1);
		map_flood_fill(map, x, y - 1);
	}
	return (map);
}

/*
** Checks if both player and exit characters no longer exist 
** in the map after running the flood fill, which effectively 
** means there is a walkable path between the two.
*/

int	map_path_check(char **map)
{
	t_map	coords;

	coords.player_x = 0;
	coords = coords_player_exit(map, coords);
	map = map_flood_fill(map, coords.player_x, coords.player_y);
	if (map[coords.exit_y][coords.exit_x] == 'F')
		return (0);
	return (1);
}
