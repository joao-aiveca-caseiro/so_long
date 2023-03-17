/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 04:23:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 06:59:58 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_count_to_window(t_win window)
{
	char	*move_count;
	char	*mc_str;

	move_count = ft_itoa(window.move_count);
	mc_str = ft_strjoin("Moves: ", move_count);
	mlx_string_put(window.mlx_ptr, window.win_ptr, 32, 18, 0xFFFCC9, mc_str);
	free(move_count);
	free(mc_str);
}

int	close_window(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (0);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

t_size	map_size_tiles(char **map, t_size map_size)
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
	map_size.width = x;
	map_size.height = y;
	return (map_size);
}
