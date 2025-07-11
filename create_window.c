/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:40:50 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/11 14:50:50 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	create_window(t_map *map_data, t_mlx *mlx_data)
{
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
		PICTURE_SIZE * map_data->width,
		PICTURE_SIZE * map_data->height, GAME_NAME);
	if (!mlx_data->win_ptr)
		//Or... Just clean and exit here
		return (0);
	return (1);
}
