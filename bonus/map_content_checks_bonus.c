/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_checks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:06 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 07:06:42 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
** Checks if the map is a rectangle, 
** by comparing the length of each row. 
*/

int	map_rectangle_check(char **map)
{
	int		i;
	size_t	prev;

	i = 1;
	prev = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != prev)
			return (1);
		i++;
	}
	return (0);
}

/*
** Checks if the map is surrounded by walls. 
*/

int	map_wall_check(char **map)
{
	size_t	i;
	size_t	j;
	size_t	map_rows;

	i = -1;
	j = 0;
	while (map[j])
		j++;
	map_rows = j;
	j = -1;
	while (map[++j])
	{
		if (j == 0 || j == map_rows - 1)
		{
			while (map[j][++i])
				if (map[j][i] != '1')
					return (1);
		}
		else
			if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
				return (1);
		i = -1;
	}
	return (0);
}

/*
** Checks if the map fits the screen window,
** taking into account 32px tiles. Not asked by 
** the subject, but necessary to ensure playability. 
*/

int	map_size_check(char **map)
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
	if ((1920 / (x * 32) > 0) && (1080 / (y * 32) > 0))
		return (0);
	else
		return (1);
}

/*
** Checks if the map contains the correct number of 
** player, exit and collectible characters, and also 
** if there are no other character besides the ones allowed.
*/

int	map_char_check(char **map)
{
	t_map	count;
	int		j;
	int		i;

	i = -1;
	j = -1;
	count.collect = 0;
	count.exit = 0;
	count.player = 0;
	count.illegal = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			count = map_count_chars(map, j, i, count);
		}
		i = -1;
	}
	if (count.player != 1 || count.exit != 1 \
	|| count.collect == 0 || count.illegal != 0)
		return (1);
	return (0);
}

t_map	map_count_chars(char **map, int j, int i, t_map count)
{
	if (map[j][i] == 'P')
		count.player++;
	else if (map[j][i] == 'C')
		count.collect++;
	else if (map[j][i] == 'E')
		count.exit++;
	else if (map[j][i] != '1' && map[j][i] != '0')
		count.illegal++;
	return (count);
}
