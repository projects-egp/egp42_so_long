/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_execute_and_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:00:04 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 22:27:45 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	print_moves(int moves)
{
	char	*moves_str;

	moves_str = NULL;
	moves_str = ft_itoa(moves);
	ft_putstr("You have moved ");
	if (!moves_str)
		ft_printf("%d times.\n", moves);
	else
	{
		ft_putstr(moves_str);
		ft_putendl(" times.");
		free(moves_str);
	}
}

void	special_event(t_mlx *mlx, t_map *data, char target)
{
	int	x_exit;
	int	y_exit;

	if (target == 'c')
		data->c_flag -= 1;
	if (data->c_flag == 0)
	{
		x_exit = data->e_position[0];
		y_exit = data->e_position[1];
		data->map[y_exit][x_exit] = 'f';
		choose_tile_to_print(mlx, data->map, x_exit, y_exit);
	}
	if (target == 'f')
	{
		ft_putendl("\n\nFINISHED!! HERE WE GOOOO!!!");
		ft_putendl("'My dream... Is to fly...'");
		destroy_requested(mlx);
	}
}

void	rotate_player(int key, int x, int y, t_map *player)
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

char	set_target(int key, int x, int y, t_map *data)
{
	char	target;

	target = 0;
	if (key == UP)
		target = data->map[y - 1][x];
	if (key == RIGHT)
		target = data->map[y][x + 1];
	if (key == DOWN)
		target = data->map[y + 1][x];
	if (key == LEFT)
		target = data->map[y][x - 1];
	return (target);
}

void	execute_move(int key, int x, int y, t_map *data)
{
	if (key == UP)
	{
		data->p_position[1] -= 1;
		rotate_player(key, x, (y - 1), data);
	}
	if (key == RIGHT)
	{
		data->p_position[0] += 1;
		rotate_player(key, (x + 1), y, data);
	}
	if (key == DOWN)
	{
		data->p_position[1] += 1;
		rotate_player(key, x, (y + 1), data);
	}
	if (key == LEFT)
	{
		data->p_position[0] -= 1;
		rotate_player(key, (x - 1), y, data);
	}
}
