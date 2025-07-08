/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:35:07 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/08 23:02:57 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	initialize_map_data(t_map *map_data)
{
	map_data->map = NULL;
	map_data->height = 0;
	map_data->width = 0;
	map_data->p_flag = 0;
	map_data->c_flag = 0;
	map_data->e_flag = 0;
	map_data->error_flag = 0;
}

//Open map_pathname twice: once for check, next to flodfill and create window
void	open_map(char *map_pathname, t_map *map_data)
{
	t_list	lines;
	int		fd_map;
	
	lines = NULL;
	initialize_map_data(map_data);
	fd_map = open(map_pathname, O_RDONLY);
	if (fd_map == -1)
		map_data->error_flag = 1;
	check_line_by_line(fd_map, map_data, &lines);
	//store in map_data->map, free nodes from lines
	//flodfill
	close(fd_map);
}
