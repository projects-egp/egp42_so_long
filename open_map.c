/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:35:07 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 19:48:55 by enrgil-p         ###   ########.fr       */
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

static void	store_map(t_map *data, t_list **lines)
{
	int	i;

	i = data->height;
	data->map = ft_calloc(data->height + 1, sizeof(char *));
	if (!data->map)
	{
		free_full_list(lines);
		ft_putendl_error("Error\nMalloc fail");
		exit(EXIT_FAILURE);
	}
	while (i > 0)
	{
		data->map[i] = ft_substr((*lines)->content, 0, data->width);
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
		flood_fill(data, x, y - 1);
		flood_fill(data, x + 1, y);
		flood_fill(data, x, y + 1);
		flood_fill(data, x - 1, y);
	}
}

static int	can_reach_special_cells(t_map *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data->map[line])
	{
		while (data->map[line][i]
			&& !ft_strchr("PCE", data->map[line][i]))
			i++;
		if (data->map[line][i] != '\0')
		{
			data->error_flag = 8;
			return (0);
		}
		i = 0;
		line++;
	}
	return (1);
}

int	open_map(char *map_pathname, t_map *map_data)
{
	t_list	*lines;
	int		fd_map;

	lines = NULL;
	initialize_map_data(map_data);
	fd_map = open(map_pathname, O_RDONLY);
	if (fd_map == -1)
		return (0);
	check_line_by_line(fd_map, map_data, &lines);
	close(fd_map);
	store_map(map_data, &lines);
	flood_fill(map_data, map_data->p_position[0], map_data->p_position[1]);
	if (!can_reach_special_cells(map_data))
		print_error(map_data);
	return (1);
}
