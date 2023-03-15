/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:16:08 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/15 03:55:08 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_win window, t_img image, int x, int y)
{
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image.img_ptr, x, y);
}

void	render_image_alpha(t_win window, t_img image, int x, int y)
{
	t_img	image_alpha;

	// image_alpha.addr = ft_strdup(image.addr);
	image_alpha.addr = malloc(sizeof(char) * 1000);
	ft_printf("Success\n");
	image_alpha.bpp = image.bpp;
	image_alpha.endian = image.endian;
	image_alpha.h = image.h;
	image_alpha.w = image.w;
	image_alpha.line_len = image.line_len;
	image_alpha.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, "enemy.xpm", &(image.w), &(image.h));
	ft_printf("Success2\n");
	make_alpha_img(image_alpha, image, 0, 0);
	ft_printf("Success3\n");
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, image_alpha.img_ptr, x, y);
	free(image_alpha.addr);
	free(image_alpha.img_ptr);
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

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.line_len) + (x * img.bpp / 8))));
}

static int	put_pixel_valid(t_img img, int x, int y)
{
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		return (*(unsigned int *)(img.addr + (y * img.line_len + x * (img.bpp / 8))) != 0xFF000000 &&
		*(unsigned int *)(img.addr + (y * img.line_len + x * (img.bpp / 8))) != 0x00000000);
	}
	return (0);
}

void	make_alpha_img(t_img dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("Entered make alpha img\n");
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			if (put_pixel_valid(src, i, j))
			{
				put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			}
			j++;
		}
		i++;
	}
}
