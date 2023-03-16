/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 23:12:12 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/16 17:25:37 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	load_animations(t_win window)
{
	window.anim.frame_1 = new_file_img("sprites/enemy2.xpm", window);
	window.anim.frame_2 = new_file_img("sprites/enemy3.xpm", window);
	window.anim.frame_3 = new_file_img("sprites/enemy4.xpm", window);
	window.anim.frame_4 = new_file_img("sprites/enemy5.xpm", window);
	window.anim.frame_5 = new_file_img("sprites/enemy6.xpm", window);
	window.anim.frame_6 = new_file_img("sprites/enemy7.xpm", window);
	window.anim.frame_7 = new_file_img("sprites/enemy8.xpm", window);
	window.anim.frame_8 = new_file_img("sprites/enemy9.xpm", window);
	window.anim.frame_9 = new_file_img("sprites/enemy10.xpm", window);
	window.anim.frame_10 = new_file_img("sprites/enemy11.xpm", window);
	window.anim.frame_11 = new_file_img("sprites/enemy12.xpm", window);
	window.anim.frame_12 = new_file_img("sprites/enemy13.xpm", window);
	window.anim.frame_13 = new_file_img("sprites/enemy14.xpm", window);
	window.anim.frame_14 = new_file_img("sprites/enemy15.xpm", window);
	window.anim.frame_15 = new_file_img("sprites/enemy16.xpm", window);
	window.anim.frame_16 = new_file_img("sprites/enemy17.xpm", window);
	window.anim.frame_17 = new_file_img("sprites/enemy18.xpm", window);
	window.anim.frame_18 = new_file_img("sprites/enemy19.xpm", window);
	window.anim.frame_19 = new_file_img("sprites/enemy20.xpm", window);
	window.anim.frame_20 = new_file_img("sprites/enemy21.xpm", window);
	window.anim.frame_21 = new_file_img("sprites/enemy22.xpm", window);
	window.anim.frame_22 = new_file_img("sprites/enemy23.xpm", window);
	window.anim.frame_23 = new_file_img("sprites/enemy24.xpm", window);
	return (window);
}

void	animate_enemies(t_win window, int sprite_nb)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	
	while (window.map[++y])
	{
		while (window.map[y][++x])
		{
			if (window.map[y][x] == 'N' && sprite_nb == 1)
				render_image(window, window.anim.frame_1, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 2)
				render_image(window, window.anim.frame_2, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 3)
				render_image(window, window.anim.frame_3, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 4)
				render_image(window, window.anim.frame_4, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 5)
				render_image(window, window.anim.frame_5, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 6)
				render_image(window, window.anim.frame_6, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 7)
				render_image(window, window.anim.frame_7, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 8)
				render_image(window, window.anim.frame_8, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 9)
				render_image(window, window.anim.frame_9, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 10)
				render_image(window, window.anim.frame_10, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 11)
				render_image(window, window.anim.frame_11, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 12)
				render_image(window, window.anim.frame_12, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 13)
				render_image(window, window.anim.frame_13, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 14)
				render_image(window, window.anim.frame_14, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 15)
				render_image(window, window.anim.frame_15, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 16)
				render_image(window, window.anim.frame_16, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 17)
				render_image(window, window.anim.frame_17, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 18)
				render_image(window, window.anim.frame_18, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 19)
				render_image(window, window.anim.frame_19, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 20)
				render_image(window, window.anim.frame_20, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 21)
				render_image(window, window.anim.frame_21, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 22)
				render_image(window, window.anim.frame_22, x * 32, y * 32);
			else if (window.map[y][x] == 'N' && sprite_nb == 23)
				render_image(window, window.anim.frame_23, x * 32, y * 32);
		}
		x = -1;
	}
}
