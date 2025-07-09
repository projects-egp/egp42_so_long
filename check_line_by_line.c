/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_by_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:20:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 17:20:50 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	wall_check(char *line, t_map *map_data)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
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
			map_data->error_flag = 1;
		map_data->p_position[0] = x_pos;
		map_data->p_position[1] = map_data->height + 1;
	}
	if (item == 'C')
		map_data->c_flag++;
	if (item == 'E')
	{
		map_data->e_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = 2;
	}
}

static void	check_forbidden_chars(char *line, t_map *map_data)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = check_width(line, map_data);
	if (!map_data->error_flag && line[0] != 1 && line[line_len] != 1)
		map_data->error_flag = 5;
	while (line[i] && !map_data->error_flag)
	{
		if (ft_strchr("PCE", line[i]))
		       	increase_pce_flags(line[i], i, map_data);
		else if (!ft_strchr("01\n", line[i]))
			map_data->error_flag = 6;
		i++;
	}
}

static int	map_is_correct(t_map *map_data, t_list *lines_list)
{
	t_list	*last_node;

	last_node = ft_lstlast(lines_list);
	if (!wall_check(lines_list->content, map_data)
		|| !wall_check(last_node->content, map_data))
		map_data->error_flag = 5;
	if (map_data->p_flag != 1)
		map_data->error_flag = 1;
	else if (map_data->e_flag != 1)
		map_data->error_flag = 2;
	else if (map_data->c_flag < 1)
		map_data->error_flag = 3;
	else if (map_data->width <= 2 || map_data->height <= 2
		|| (map_data->width * map_data->height) < 15)//Add max size
		map_data->error_flag = 4;
	if (!map_data->error_flag)
		return (1);
	return (0);
}

void	check_line_by_line(int fd, t_map *map_data, t_list *lines)
{
	char	*read_line;
	t_list	*new_line;

	read_line = "";
	while (read_line && !map_data->error_flag)
	{
		read_line = get_next_line(fd);
		if (!read_line && !lines)
			map_data->error_flag = 7;
		check_forbidden_chars(read_line, map_data);
		if (!map_data->error_flag)
		{
			new_line = ft_lstnew(read_line);
			ft_lstadd_front(&lines, new_line);
	/*Store this in another function, and free and close things properly 
 	*in case of error*/    //Should free new if every is okay??
			map_data->height++;
		}
		free(read_line);
	}
	if (map_data->error_flag || !map_is_correct(map_data, lines))
	{
		close(fd);
		clean_list(lines);
		print_error(map_data);
	}
}
