/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:16:08 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/07 15:26:54 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image(t_win window, char *filename, int x, int y)
{
	t_img	image;
	char	*image_file;

	image_file = ft_strjoin(filename, ".xpm");
	image = new_file_img(image_file, window);
	mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, x, y);
	free(image_file);
}
