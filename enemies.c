/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:07:46 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/15 03:56:36 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**spawn_enemies(char **map)
{
	int	x;
	int	y;
	int	n;
	int	spawned;

	x = -1;
	y = -1;
	n = 0;
	spawned = 0;
	srand(time(0));
	while (map[++y])
	{
		while (map[y][++x])
		{	
			n = rand() % 42;
			if (map[y][x] == '0' && n == 1)
			{
				map[y][x] = 'N';
				spawned = 1;	
			}
		}
		x = -1;
	}
	if (spawned == 0)
		map = spawn_enemies(map);
	return (map);
}

t_win	refresh_moves(t_win window)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (window.map[++y])
	{
		while (window.map[y][++x])
			if (window.map[y][x] == 'n')
				window.map[y][x] = 'N';
		x = -1;
	}
	return (window);
}

t_win	move_enemies(t_win window)
{
	int	x;
	int	y;
	int	n;

	x = -1;
	y = -1;
	n = 0;
	srand(time(0));
	while (window.map[++y])
	{
		while (window.map[y][++x])
		{
			n = rand() % 4;
			if (window.map[y][x] == 'N' && window.map[y][x + 1] == '0' && n == 0)
			{
				window.map[y][x] = '0';
				window.map[y][x + 1] = 'n';
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32 + 32, y * 32);
			}
			else if (window.map[y][x] == 'N' && window.map[y][x - 1] == '0' && n == 1)
			{
				window.map[y][x] = '0';
				window.map[y][x - 1] = 'n';
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32 - 32, y * 32);
			}
			else if (window.map[y][x] == 'N' && window.map[y + 1][x] == '0' && n == 2)
			{
				window.map[y][x] = '0';
				window.map[y + 1][x] = 'n';
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32, y * 32 + 32);
			}
			else if (window.map[y][x] == 'N' && window.map[y - 1][x] == '0' && n == 3)
			{
				window.map[y][x] = '0';
				window.map[y - 1][x] = 'n';
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32, y * 32 - 32);
			}
		}
		x = -1;
	}
	window = refresh_moves(window);
	return (window);
}
