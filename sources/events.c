/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:51 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 04:24:08 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible_count(t_win	window)
{
	int	x;
	int	y;
	int	count;

	x = -1;
	y = -1;
	count = 0;
	while (window.map[++y])
	{
		while (window.map[y][++x])
			if (window.map[y][x] == 'C')
				count++;
		x = -1;
	}
	return (count);
}

int	player_count(t_win	window)
{
	int	x;
	int	y;
	int	count;

	x = -1;
	y = -1;
	count = 0;
	while (window.map[++y])
	{
		while (window.map[y][++x])
			if (window.map[y][x] == 'P')
				count++;
		x = -1;
	}
	return (count);
}

void	trigger_game_end(t_win window)
{
	if (window.defeat_count == 1)
		trigger_defeat(window);
	else if (window.victory_count == 1)
		trigger_victory(window);
}

void	trigger_victory(t_win window)
{
	render_image(window, window.victory, \
		window.width / 2 - 80, window.height / 2 - 48);
}

void	trigger_defeat(t_win window)
{
	render_image(window, window.defeat, \
		window.width / 2 - 80, window.height / 2 - 48);
}
