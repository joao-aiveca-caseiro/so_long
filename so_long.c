/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:15:33 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/03/06 03:38:12 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int width, int height, char *name)
{
	void	*mlx_ptr;
	t_win	new_program;

	mlx_ptr = mlx_init();
	new_program.mlx_ptr = mlx_ptr;
	new_program.win_ptr = mlx_new_window(mlx_ptr, width, height, name);
	new_program.width = width;
	new_program.height = height;
	return (new_program);
}

t_img	new_img(int width, int height, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, width, height);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	image.w = width;
	image.h = height;
	return (image);
}

t_img	new_file_img(char *path, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &(image.w), &(image.h));
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp), \
	&(image.line_len), &(image.endian));
	return (image);
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

int	exit_tutorial(t_win *window)
{
	mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	exit (0);
}

int	key_press(int keycode, t_win *window)
{
	ft_printf("keycode=%i\n", keycode);
	if (keycode == 65307)
		exit_tutorial(window);
	return (0);
}

int	map_rectangle_check(char **map)
{
	int		i;
	size_t	prev;

	i = 1;
	prev = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != prev)
			return (1);
		i++;
	}
	return (0);
}

int	map_wall_check(char **map)
{
	size_t	i;
	size_t	j;
	size_t	map_rows;

	i = -1;
	j = 0;
	while (map[j])
		j++;
	map_rows = j;
	j = -1;
	while (map[++j])
	{
		if (j == 0 || j == map_rows - 1)
		{
			while (map[j][++i])
				if (map[j][i] != '1')
					return (1);
		}
		else
			if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
				return (1);
		i = -1;
	}
	return (0);
}

int	map_char_check(char **map)
{
	t_map	count;
	int		j;
	int		i;

	i = -1;
	j = -1;
	count.collect = 0;
	count.exit = 0;
	count.player = 0;
	count.illegal = 0;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == 'P')
				count.player++;
			else if (map[j][i] == 'C')
				count.collect++;
			else if (map[j][i] == 'E')
				count.exit++;
			else if (map[j][i] != '1' && map[j][i] != '0')
				count.illegal++;
		}
		i = -1;
	}
	if (count.player != 1 || count.exit != 1 \
	|| count.collect == 0 || count.illegal != 0)
		return (1);
	return (0);
}

void	validate_map(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		ft_printf("line %i: %s\n", j, map[j]);
		j++;
	}
	if (map_rectangle_check(map) == 1)
	{
		ft_putstr_fd("Error: map is not a rectangle.\n", 2);
		exit (1);
	}
	else if (map_wall_check(map) == 1)
	{
		ft_putstr_fd("Error: map isn't surrounded by walls.\n", 2);
		exit (1);
	}
	else if (map_char_check(map) == 1)
	{
		ft_putstr_fd("Error: map has invalid type or number of characters.\n", 2);
		exit (1);
	}
}

void	read_map(char *arg)
{
	int		map_file;
	char	*map_string;
	char	*temp;
	char	**map_2d_array;

	map_file = open(arg, O_RDONLY);
	if (map_file == -1)
		exit (1);
	temp = ft_calloc(1, 1);
	map_string = ft_calloc(1, 1);
	while (read(map_file, temp, 1) != 0)
		map_string = strjoin_gnl(map_string, temp);
	map_2d_array = ft_split(map_string, '\n');
	free(map_string);
	free(temp);
	validate_map(map_2d_array);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		read_map(argv[1]);
	// t_win	so_long;

	// so_long = new_program(1000, 1000, "So Long");

	// t_img	image;
	
	// image = new_file_img("gecko.xpm", so_long);
	// put_pixel_img(image, 32, 32, 0x00FFFFFF);
	// mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 500, 500);

	// mlx_hook(so_long.win_ptr, 17, 0, exit_tutorial, &so_long);
	// mlx_hook(so_long.win_ptr, 2, 1L << 0, key_press, &so_long);
	// mlx_loop(so_long.mlx_ptr);
}
