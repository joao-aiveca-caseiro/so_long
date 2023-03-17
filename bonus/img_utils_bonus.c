/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:16:08 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/17 07:06:39 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_image(t_win window, t_img image, int x, int y)
{
	mlx_put_image_to_window(window.mlx_ptr, \
		window.win_ptr, image.img_ptr, x, y);
}

t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, \
		path, &(image.w), &(image.h));
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	return (image);
}

t_win	load_images(t_win window)
{
	window.player_d = new_file_img("sprites/player_d.xpm", window);
	window.player_u = new_file_img("sprites/player_u.xpm", window);
	window.player_r = new_file_img("sprites/player_r.xpm", window);
	window.player_l = new_file_img("sprites/player_l.xpm", window);
	window.enemy = new_file_img("sprites/enemy.xpm", window);
	window.floor = new_file_img("sprites/floor.xpm", window);
	window.wall_full = new_file_img("sprites/wall_full.xpm", window);
	window.wall_left = new_file_img("sprites/wall_left.xpm", window);
	window.wall_right = new_file_img("sprites/wall_right.xpm", window);
	window.wall_top = new_file_img("sprites/wall_top.xpm", window);
	window.wall_bottom = new_file_img("sprites/wall_bottom.xpm", window);
	window.wall_clear = new_file_img("sprites/wall_clear.xpm", window);
	window.exit = new_file_img("sprites/exit.xpm", window);
	window.collectible = new_file_img("sprites/collectible.xpm", window);
	window.victory = new_file_img("sprites/victory.xpm", window);
	window.defeat = new_file_img("sprites/defeat.xpm", window);
	return (window);
}
