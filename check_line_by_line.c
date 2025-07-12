/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_by_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:20:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 14:01:32 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	wall_check(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1') 
			return (0);
		i++;
	}
	return (1);
}

static void	increase_pce_flags(char item, int x_pos, t_map *map_data)
{
	if (item == 'P')
	{
		map_data->p_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = WRONG_P;
		map_data->p_position[0] = x_pos;
		map_data->p_position[1] = map_data->height;
	}
	if (item == 'C')
		map_data->c_flag++;
	if (item == 'E')
	{
		map_data->e_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = WRONG_E;
		map_data->e_position[0] = x_pos;
		map_data->e_position[1] = map_data->height;
	}
}

static void	check_forbidden_chars(char *line, t_map *map_data)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = check_width(line, map_data);
	if (!map_data->error_flag
		&& (line[0] != '1' || line[line_len - 1] != '1'))
		map_data->error_flag = WRONG_WALL;
	while (line[i] && !map_data->error_flag)
	{
		if (ft_strchr("PCE", line[i]))
			increase_pce_flags(line[i], i, map_data);
		else if (!ft_strchr("01\n", line[i]))
			map_data->error_flag = 6;
		i++;
	}
}

static int	map_is_correct(t_map *map_data, t_list **lines_list)
{
	t_list	*last_node;
	int		map_size;

	map_size = map_data->width * map_data->height;
	last_node = ft_lstlast(*lines_list);
	if (map_data->width <= 2 || map_data->height <= 2
		|| map_data->width <= 60 || map_data->height <= 32
		|| map_size < MIN_MAP_SIZE || map_size > MAX_MAP_SIZE)
		map_data->error_flag = WRONG_SIZE;
	else if (!wall_check((*lines_list)->content)
		|| !wall_check(last_node->content))
		map_data->error_flag = WRONG_WALL;
	else if (map_data->p_flag != 1)
		map_data->error_flag = WRONG_P;
	else if (map_data->e_flag != 1)
		map_data->error_flag = WRONG_E;
	else if (map_data->c_flag < 1)
		map_data->error_flag = WRONG_C;
	if (!map_data->error_flag)
		return (1);
	return (0);
}

void	check_line_by_line(int fd, t_map *map_data, t_list **lines)
{
	char	*read_line;

	read_line = " ";
	while (read_line && !map_data->error_flag)
	{
		read_line = get_next_line_extra(fd, 1);
		if (!read_line && !lines)
			map_data->error_flag = EMPTY_FILE;
		if (read_line && read_line[0] != '\0')
			check_forbidden_chars(read_line, map_data);
		if (!map_data->error_flag && read_line && read_line[0] != 0)
		{
			add_new_line(read_line, lines, map_data);
			map_data->height++;
		}
		if (read_line && read_line[0] == 0)
			free_string_and_null(&read_line);
		if (map_data->error_flag)
			get_next_line_extra(fd, 0);
	}
	if (map_data->error_flag || !map_is_correct(map_data, lines))
		close_clean_and_exit_error(fd, read_line, lines, map_data);
}
