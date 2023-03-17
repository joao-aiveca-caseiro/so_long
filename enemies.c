/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:07:46 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/16 22:30:07 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**spawn_enemies(char **map, int spawned)
{
	int	x;
	int	y;
	int	n;

	x = -1;
	y = -1;
	n = 0;
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
		map = spawn_enemies(map, 1);
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
			if (window.map[y][x] == 'N' && (window.map[y][x + 1] == '0' || window.map[y][x + 1] == 'P') && n == 0)
			{
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32 + 32, y * 32);
				if (window.map[y][x + 1] == 'P')
					trigger_defeat();
				window.map[y][x] = '0';
				window.map[y][x + 1] = 'n';
			}
			else if (window.map[y][x] == 'N' && (window.map[y][x - 1] == '0' || window.map[y][x - 1] == 'P') && n == 1)
			{
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32 - 32, y * 32);
				if (window.map[y][x - 1] == 'P')
					trigger_defeat();
				window.map[y][x] = '0';
				window.map[y][x - 1] = 'n';
			}
			else if (window.map[y][x] == 'N' && (window.map[y + 1][x] == '0' || window.map[y + 1][x] == 'P') && n == 2)
			{
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32, y * 32 + 32);
				if (window.map[y + 1][x] == 'P')
					trigger_defeat();
				window.map[y][x] = '0';
				window.map[y + 1][x] = 'n';
			}
			else if (window.map[y][x] == 'N' && (window.map[y - 1][x] == '0' || window.map[y - 1][x] == 'P') && n == 3)
			{
				render_image(window, window.floor, x * 32, y * 32);
				render_image(window, window.enemy, x * 32, y * 32 - 32);
				if (window.map[y - 1][x] == 'P')
					trigger_defeat();
				window.map[y][x] = '0';
				window.map[y - 1][x] = 'n';
			}
		}
		x = -1;
	}
	window = refresh_moves(window);
	return (window);
}
