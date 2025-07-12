/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 14:29:59 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	initialize_mlx_data(t_mlx *mlx_data, t_map *map)
{
	mlx_data->map_data = map;
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->img_grass = NULL;
	mlx_data->img_item = NULL;
	mlx_data->img_pilot_down = NULL;
	mlx_data->img_pilot_left = NULL;
	mlx_data->img_pilot_right = NULL;
	mlx_data->img_pilot_up = NULL;
	mlx_data->img_plane = NULL;
	mlx_data->img_plane_repaired = NULL;
	mlx_data->img_tree = NULL;
	mlx_data->moves = 0;
	mlx_data->error_flag = 0;
}

static void	create_window(t_map *map_data, t_mlx *mlx_data)
{
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
			PICTURE_SIZE * map_data->width,
			PICTURE_SIZE * map_data->height, GAME_NAME);
	if (!mlx_data->win_ptr)
	{
		mlx_data->error_flag = 1;
		ft_putendl_error("Error\n Create window with mlx failed");
		destroy_requested(mlx_data);
	}
}

static void	connect_x_window(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
		mlx_data->error_flag = 1;
		ft_putendl_error("Error\n Init mlx failed");
		destroy_requested(mlx_data);
	}
	create_window(mlx_data->map_data, mlx_data);
	print_map(mlx_data->map_data, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 1L << 0, key_press, mlx_data);
	mlx_hook(mlx_data->win_ptr, 17, 1L << 17, destroy_requested, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}

int	main(int arg_counter, char **arg_vector)
{
	t_map	map_data;
	t_mlx	mlx_data;

	if (arg_counter == 2)
	{
		map_format(arg_vector[1]);
		if (!open_map(arg_vector[1], &map_data))
		{
			ft_putstr_fd("Error\nFail trying to open ", 2);
			ft_putendl_error(arg_vector[1]);
			return (1);
		}
		initialize_mlx_data(&mlx_data, &map_data);
		connect_x_window(&mlx_data);
		free_strings_array(map_data.map);
		return (0);
	}
	ft_putstr_fd("Error\nExpected: ./so_long ", 2);
	ft_putendl_error(EXPECTED_FORMAT);
	return (1);
}
