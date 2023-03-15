/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:16:08 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/15 15:47:21 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_win window, t_img image, int x, int y)
{
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, x, y);
}


t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &(image.w), &(image.h));
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	return (image);
}

t_win	load_images(t_win window)
{
	window.player = new_file_img("player.xpm", window);
	window.enemy = new_file_img("enemy.xpm", window);
	window.floor = new_file_img("floor.xpm", window);
	window.wall = new_file_img("wall.xpm", window);
	window.exit = new_file_img("exit.xpm", window);
	window.collectible = new_file_img("collectible.xpm", window);
	return (window);
}
