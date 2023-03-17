/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:14:55 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 07:27:06 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Manages player movement, triggering a function for the pressed 
** direction if it is walkable. Also cleans the bonus move display 
** in the map, allowing it to be filled by the next number of moves.
** Lastly, triggers enemy movement and checks if the victory or defeat
** conditions are met, ending the game.
*/

t_win	player_move(char dir, t_win window)
{
	t_map	coords;

	coords.collect = 0;
	window.victory_count = 0;
	window.defeat_count = 0;
	if (player_count(window) == 0)
		close_window(&window);
	coords = coords_player_exit(window.map, coords);
	render_image(window, window.wall_top, 32, 0);
	render_image(window, window.wall_top, 64, 0);
	if (dir == 'r' && (window.map[coords.player_y][coords.player_x + 1] != '1'))
		window = player_move_right(window, coords);
	else if (dir == 'l'
		&& (window.map[coords.player_y][coords.player_x - 1] != '1'))
		window = player_move_left(window, coords);
	else if (dir == 'd'
		&& (window.map[coords.player_y + 1][coords.player_x] != '1'))
		window = player_move_down(window, coords);
	else if (dir == 'u'
		&& (window.map[coords.player_y - 1][coords.player_x] != '1'))
		window = player_move_up(window, coords);
	trigger_game_end(window);
	return (window);
}

t_win	player_move_right(t_win window, t_map coords)
{
	if (window.map[coords.player_y][coords.player_x + 1] == 'E'
		&& collectible_count(window) == 0)
		window.victory_count = 1;
	if (window.map[coords.player_y][coords.player_x + 1] == 'N')
		window.defeat_count = 1;
	if (window.map[coords.player_y][coords.player_x + 1] != 'E'
		|| window.victory_count == 1)
	{
		render_image(window, window.floor, \
			coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player_r, \
			coords.player_x * 32 + 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		if (window.victory_count != 1 && window.defeat_count != 1)
			window.map[coords.player_y][coords.player_x + 1] = 'P';
		window.move_count = window.move_count + 1;
		ft_printf("Moves: %i\n", window.move_count);
	}
	return (window);
}

t_win	player_move_left(t_win window, t_map coords)
{
	if (window.map[coords.player_y][coords.player_x - 1] == 'E'
		&& collectible_count(window) == 0)
		window.victory_count = 1;
	if (window.map[coords.player_y][coords.player_x - 1] == 'N')
		window.defeat_count = 1;
	if (window.map[coords.player_y][coords.player_x - 1] != 'E'
		|| window.victory_count == 1)
	{
		render_image(window, window.floor, \
			coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player_l, \
			coords.player_x * 32 - 32, coords.player_y * 32);
		window.map[coords.player_y][coords.player_x] = '0';
		if (window.victory_count != 1 && window.defeat_count != 1)
			window.map[coords.player_y][coords.player_x - 1] = 'P';
		window.move_count = window.move_count + 1;
		ft_printf("Moves: %i\n", window.move_count);
	}
	return (window);
}

t_win	player_move_up(t_win window, t_map coords)
{
	if (window.map[coords.player_y - 1][coords.player_x] == 'E'
		&& collectible_count(window) == 0)
		window.victory_count = 1;
	if (window.map[coords.player_y - 1][coords.player_x] == 'N')
		window.defeat_count = 1;
	if (window.map[coords.player_y - 1][coords.player_x] != 'E'
		|| window.victory_count == 1)
	{
		render_image(window, window.floor, \
			coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player_u, \
			coords.player_x * 32, coords.player_y * 32 - 32);
		window.map[coords.player_y][coords.player_x] = '0';
		if (window.victory_count != 1 && window.defeat_count != 1)
			window.map[coords.player_y - 1][coords.player_x] = 'P';
		window.move_count = window.move_count + 1;
		ft_printf("Moves: %i\n", window.move_count);
	}
	return (window);
}

t_win	player_move_down(t_win window, t_map coords)
{
	if (window.map[coords.player_y + 1][coords.player_x] == 'E'
		&& collectible_count(window) == 0)
		window.victory_count = 1;
	if (window.map[coords.player_y + 1][coords.player_x] == 'N')
		window.defeat_count = 1;
	if (window.map[coords.player_y + 1][coords.player_x] != 'E'
		|| window.victory_count == 1)
	{
		render_image(window, window.floor, \
			coords.player_x * 32, coords.player_y * 32);
		render_image(window, window.player_d, \
			coords.player_x * 32, coords.player_y * 32 + 32);
		window.map[coords.player_y][coords.player_x] = '0';
		if (window.victory_count != 1 && window.defeat_count != 1)
			window.map[coords.player_y + 1][coords.player_x] = 'P';
		window.move_count = window.move_count + 1;
		ft_printf("Moves: %i\n", window.move_count);
	}
	return (window);
}
