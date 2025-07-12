/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:13:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 14:12:52 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	remove_images(t_mlx *mlx)
{
	if (mlx->img_grass)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_grass);
	if (mlx->img_item)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_item);
	if (mlx->img_pilot_down)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_pilot_down);
	if (mlx->img_pilot_left)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_pilot_left);
	if (mlx->img_pilot_right)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_pilot_right);
	if (mlx->img_pilot_up)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_pilot_up);
	if (mlx->img_plane)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_plane);
	if (mlx->img_plane_repaired)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_plane_repaired);
	if (mlx->img_tree)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_tree);
}

int	destroy_requested(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	remove_images(mlx);
	free_strings_array(mlx->map_data->map);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	if (!mlx->error_flag)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
	return (0);
}

static void	move_player(int key, t_mlx *mlx, t_map *data_from, char target)
{
	int	x;
	int	y;

	x = data_from->p_position[0];
	y = data_from->p_position[1];
	if (key == UP || key == RIGHT || key == DOWN || key == LEFT)
	{
		mlx->moves++;
		print_moves(mlx->moves);
		data_from->map[y][x] = 'o';
		choose_tile_to_print(mlx, data_from->map, x, y);
		if (target == 'c' || target == 'f')
			special_event(mlx, data_from, target);
		execute_move(key, x, y, data_from);
		choose_tile_to_print(mlx, data_from->map,
		data_from->p_position[0], data_from->p_position[1]);
	}
}

int	key_press(int key, t_mlx *mlx)
{
	int	x;
	int	y;
	char	target;

	x = mlx->map_data->p_position[0];
	y = mlx->map_data->p_position[1];
	target = set_target(key, x, y, mlx->map_data);
	rotate_player(key, x, y, mlx->map_data);
	if (key == ESC)
		destroy_requested(mlx);
	else if (target != '1' && target != 'e')
		move_player(key, mlx, mlx->map_data, target);
	else if (key == UP || key == RIGHT || key == DOWN || key == LEFT)
		choose_tile_to_print(mlx, mlx->map_data->map, x, y);
	return (0);
}
