/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:13:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/11 21:52:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static /*Some*/	move_player(int key, t_mlx *mlx, t_map *data_from, char target)
{
	int	x;
	int	y;

	x = data_from->p_position[0];//Call this in a function
	y = data_from->p_position[1];
	mlx->moves++;
	//write moves
	data_from->map[y][x] = 'o';
	choose_tile_to_print(mlx, data_from->map, x, y);
	if (target == 'c' || target == 'f')
		special_event(data_from, target);
	execute_move(key, x, y, map);
	choose_tile_to_print(mlx, data_from->map,
		data_from->p_position[0], data_from->p_position[1]);
}

/*Something*/	key_press(t_mlx *mlx, t_map *map)
{
	int	key;//Do this go as a parameter?
	int	x;
	int	y;
	char	target;

	x = p_position[0];
	y = p_position[1];
	target = set_target(key, x, y, map->map);
	rotate_player(key, x, y, map->map);
	if (key == ESC)
		destroy();
	else if (target != '1' && target != 'e')
		move_player(key, mlx, map, target);
	//print player
}
