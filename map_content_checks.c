/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_checks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:39:06 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/06 18:55:01 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (map[j][i] == 'P')
				count.player++;
			else if (map[j][i] == 'C')
				count.collect++;
			else if (map[j][i] == 'E')
				count.exit++;
			else if (map[j][i] != '1' && map[j][i] != '0')
				count.illegal++;
		}
		i = -1;
	}
	if (count.player != 1 || count.exit != 1 \
	|| count.collect == 0 || count.illegal != 0)
		return (1);
	return (0);
}
