/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/10 20:52:55 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	initialize_mlx_data(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = NULL;
	mlx_data->win_ptr = NULL;
	mlx_data->img_ptr = NULL;
}

static void	connect_x_window(t_map *map_data, t_mlx *mlx_data)
{
	int	x;
	int	y;
	int	picture_size;

	x = 0;
	y = 0;
	picture_size = PICTURE_SIZE;
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
		ft_putendl_error("Error\n Init mlx failed");
		free_strings_array(map_data->map);//Create an error_exit
	}
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
		PICTURE_SIZE * map_data->width,
		PICTURE_SIZE * map_data->height, NAME);
	if (!mlx_data->win_ptr)
	{
		ft_putendl_error("Error\n Create window failed");
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);//Do this go here
		free_strings_array(map_data->map);//Create an error_exit
	}
	mlx_data->img_ptr = mlx_xpm_file_to_image(mlx_data->mlx_ptr,
		PILOT_DOWN, &picture_size, &picture_size);
	while (y <= map_data->height)
	{
		while (x <= map_data->width)
		{
			mlx_put_image_to_window(mlx_data->mlx_ptr,
				mlx_data->win_ptr, mlx_data->img_ptr,
				x * PICTURE_SIZE, y * PICTURE_SIZE);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_loop(mlx_data->mlx_ptr);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	mlx_destroy_display(mlx_data->mlx_ptr);
				//Also, I have to free win_ptr?
	free(mlx_data->mlx_ptr);//Do this go here
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
		initialize_mlx_data(&mlx_data);
		connect_x_window(&map_data, &mlx_data);
		free_strings_array(map_data.map);
		return (0);
	}
	ft_putstr_fd("Error\nExpected: ./so_long ", 2);
	ft_putendl_error(EXPECTED_FORMAT);
	return (1);
}
