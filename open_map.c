/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:35:07 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 19:55:00 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	initialize_map_data(t_map *map_data)
{
	ft_bzero(map_data->map, sizeof(char));
	ft_bzero(map_data->height, sizeof(int));
	ft_bzero(map_data->width, sizeof(int));
	ft_bzero(map_data->p_flag, sizeof(int));
	ft_bzero(map_data->c_flag, sizeof(int));
	ft_bzero(map_data->e_flag, sizeof(int));
	ft_bzero(map_data->error_flag, sizeof(int));
}

//Open map_pathname twice: once for check, next to flodfill and create window
void	open_map(char *map_pathname, t_map *map_data)
{
	int	fd_map;
	
	initialize_map_data(map_data);
	if (!read_and_check_map(map_pathname, map_data))
	{
		fd_map = open(map_pathname, O_RDONLY);
		if (fd_map == -1)
		/*Error message*/exit (EXIT_FAILURE);//map_data->error_flag???
	}
}
