/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:13:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 01:15:16 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	move_player(int key, t_mlx *mlx, t_map *data_from, char target)
{
	int	x;
	int	y;

	x = data_from->p_position[0];//Call this in a function
	y = data_from->p_position[1];
	mlx->moves++;
	print_moves(mlx->moves);
	data_from->map[y][x] = 'o';
	choose_tile_to_print(mlx, data_from->map, x, y);
	if (target == 'c' || target == 'f')
		special_event(data_from, target);
	execute_move(key, x, y, data_from);
	choose_tile_to_print(mlx, data_from->map,
		data_from->p_position[0], data_from->p_position[1]);
}

int	key_press(int key, t_mlx *mlx)
{
	int	x;
	int	y;
	char	target;

	x = mlx->map_data->p_position[0];
	y = mlx->map_data->p_position[1];
	target = set_target(key, x, y, mlx->map_data->map);
	rotate_player(key, x, y, mlx->map_data);
//	if (key == ESC)
//		destroy();
	/*else*/ if (target != '1' && target != 'e')
		move_player(key, mlx, mlx->map_data, target);
	return (0);
}
