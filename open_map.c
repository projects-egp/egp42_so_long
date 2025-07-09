/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:35:07 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 17:10:34 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	initialize_map_data(t_map *map_data)
{
	map_data->map = NULL;
	map_data->height = 0;
	map_data->width = 0;
	map_data->p_position[0] = 0;
	map_data->p_position[1] = 0;
	map_data->p_flag = 0;
	map_data->c_flag = 0;
	map_data->e_flag = 0;
	map_data->error_flag = 0;
}

static void	store_map(t_map *data, t_list *lines)
{
	int	i;

	i = data->height;
	data->map = ft_calloc(data->height + 1, sizeof(char *));
	if (!data->map)
	{
		free_full_list(lines);
		ft_putendl_error("Error\nMalloc fail");
		exit(EXIT_FAILURE);/*If I can't close fd yet, return 0
					and exit in open_map()*/
	}
	while (i > 0)
	{
		memcpy(data->map[i], lines->content, data->width);
		free_first_node(lines);
		i--;
	}
}

static void	flood_fill(t_map *data, int x, int y)
{
	if (data->map[y][x] != '1')
	{
		if (ft_is_upper(data->map[y][x]))
			data->map[y][x] += 32;
		if (data->map[y][x] == 'e')
			return ;
		if (!ft_is_lower(data->map[y][x]))
			data->map[y][x] = 'f';
		flood_fill(map_data, x, y - 1);
		flood_fill(map_data, x + 1, y);
		flood_fill(map_data, x, y + 1);
		flood_fill(map_data, x - 1, y);
	}
}

int	open_map(char *map_pathname, t_map *map_data)
{
	t_list	lines;
	int		fd_map;
	
	lines = NULL;
	initialize_map_data(map_data);
	fd_map = open(map_pathname, O_RDONLY);
	if (fd_map == -1)
		return (0);
	check_line_by_line(fd_map, map_data, &lines);
	close(fd_map);/*Did i finished with fd? If that's the case, close here
		    in case an error happen you have fd closed before*/
	store_map(map_data, &lines);
	flood_fill(map_data, map_data->p_position[0], map_data->p_position[1]);
	//if (ssome mayus)
		map_data->error_flag = 8; 
	//In case of wrong result of flodill, free map_data->map
}
