/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:28:51 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/15 04:01:42 by jaiveca-         ###   ########.fr       */
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

void	trigger_victory(void)
{
	ft_printf("Success!");
	exit (0);
}

void	trigger_defeat(void)
{
	ft_printf("You Died");
	exit (0);
}