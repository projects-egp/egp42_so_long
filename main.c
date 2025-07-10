/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/10 19:58:15 by enrgil-p         ###   ########.fr       */
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
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
	{
	free(mlx_data->mlx_ptr);
	mlx_loop(mlx_data->mlx_ptr);
	return (1);//Here?
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
		connect_x_window(&map_data, &mlx_data)
		free_strings_array(map_data.map);
		return (0);
	}
	ft_putstr_fd("Error\nExpected: ./so_long ", 2);
	ft_putendl_error(EXPECTED_FORMAT);
	return (1);
}
