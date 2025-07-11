/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 00:47:39 by enrgil-p         ###   ########.fr       */
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
}

static void	connect_x_window(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
		ft_putendl_error("Error\n Init mlx failed");
		free_strings_array(mlx_data->map_data->map);//Create an error_exit
	}
	if (!create_window(mlx_data->map_data, mlx_data))//Or exit inside, 
					       //in case of error
	{
		if (!mlx_data->win_ptr)
		ft_putendl_error("Error\n Create window failed");
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);//Do this go here
		free_strings_array(mlx_data->map_data->map);//Create an error_exit
	}
	print_map(mlx_data->map_data, mlx_data);
	mlx_hook(mlx_data->win_ptr, 2, 1L << 0, key_press, mlx_data);
//	mlx_hook(mlx_data->win_ptr, 17, 1L << 17, detroy_requested, structure);
	mlx_loop(mlx_data->mlx_ptr);//This go down
	/*	Do this in destroy hook *	*/
	/*Delete below here*/
//	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
//	mlx_destroy_display(mlx_data->mlx_ptr);
				//Also, I have to free win_ptr?
//	free(mlx_data->mlx_ptr);//Do this go here
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
