/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:00:04 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/11 22:04:49 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*some*/	special_event(t_map *data, char target)
{
	if (target == 'c')
	{
		data->c_flags -= 1;
		
	}
	else if (target == 'f')
}

/**some*/	rotate_player(int key, int x, int y, t_map *player)
{
	if (key == UP)
		player->map[y][x] = 'u';
	if (key == RIGHT)
		player->map[y][x] = 'r';
	if (key == DOWN)
		player->map[y][x] = 'p';
	if (key == LEFT)
		player->map[y][x] = 'l';
}

char	set_target(int key, int x, int y, char **map)
{
	char	target;

	target = NULL;
	if (key == UP)
		target = map[y - 1][x];
	if (key == RIGHT)
		target = map[y][x + 1];
	if (key == DOWN)
		target = map[y + 1][x];
	if (key == LEFT)
		target = map[y][x - 1];
	return (target);
}

/*Something*/	execute_move(int key, int x, int y, t_map *data)
{
	if (key == UP)
	{
		data->p_position[1] -= 1;
		rotate_player(key, x, (y - 1), data->map);
	}
	if (key == RIGHT)
	{
		data->p_position[0] += 1;
		rotate_player(key, (x + 1), y, data->map);
	}
	if (key == DOWN)
	{
		data->p_position[1] += 1;
		rotate_player(key, x, (y + 1), data->map);
	}
	if (key == LEFT)
	{
		data->p_position[0] -= 1;
		rotate_player(key, (x - 1), y, data->map);
	}
}
