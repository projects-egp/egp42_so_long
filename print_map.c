/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:53:41 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/11 18:30:51 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	link_images(t_mlx *mlx_data)
{
	int	picture_size;

	picture_size = PICTURE_SIZE;
	mlx_data->img_grass = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		GRASS, &picture_size, &picture_size);
	mlx_data->img_item = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		ITEM, &picture_size, &picture_size);
	mlx_data->img_pilot_down = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PILOT_DOWN, &picture_size, &picture_size);
	mlx_data->img_pilot_left = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PILOT_LEFT, &picture_size, &picture_size);
	mlx_data->img_pilot_right = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PILOT_RIGHT, &picture_size, &picture_size);
	mlx_data->img_pilot_up = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PILOT_UP, &picture_size, &picture_size);
	mlx_data->img_plane = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PLANE, &picture_size, &picture_size);
	mlx_data->img_plane_repaired = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PLANE_REPAIRED, &picture_size, &picture_size);
	mlx_data->img_tree = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		TREE, &picture_size, &picture_size);
	//What happen in case of error?
}

static void	print_tile(t_mlx *mlx, void *image, int x, int y)
{
	int	x_size;
	int	y_size;

	x_size = x * PICTURE_SIZE;
	y_size = y * PICTURE_SIZE;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		image, x_size, y_size);
}

static void	choose_tile_to_print(t_mlx *mlx, char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'o')
		print_tile(mlx, mlx->img_grass, x, y);
	else if (map[y][x] == '1')
		print_tile(mlx, mlx->img_tree, x, y);
	else if (map[y][x] == 'c')
		print_tile(mlx, mlx->img_item, x, y);
	else if (map[y][x] == 'e')
		print_tile(mlx, mlx->img_plane, x, y);
	else if (map[y][x] == 'f')
		print_tile(mlx, mlx->img_plane_repaired, x, y);
	else if (map[y][x] == 'p')
		print_tile(mlx, mlx->img_pilot_down, x, y);
	else if (map[y][x] == 'u')
		print_tile(mlx, mlx->img_pilot_up, x, y);
	else if (map[y][x] == 'l')
		print_tile(mlx, mlx->img_pilot_left, x, y);
	else if (map[y][x] == 'r')
		print_tile(mlx, mlx->img_pilot_right, x, y);
}

void	print_map(t_map *map_data, t_mlx *mlx_data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	link_images(mlx_data);//In case of error, clean mlx_data and map_data
	//Then, read map_data->map and print following chars
	while (y < map_data->height)
	{
		while (x < map_data->width)
		{
			choose_tile_to_print(mlx_data, map_data->map, x, y);
			x++;
		}
		y++;
		x = 0;
	}
}
