/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:20:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 22:59:34 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	top_bottom_check(char *line, t_map *map_data)
{
	int		i;

	i = 0;
	if (!map_data->bottom_flag && !line)
		map_data->error_flag = 8;
	while (!map_data->error_flag && line[i] != '\0')
	{
		if (line[i] == '\n' && !map_data->bottom_flag)
			map_data->width = i;
		else if (line[i] != '1')
			map_data->error_flag = 7;
		i++;
	}
	ft_printf("widdth is %d, i is %d\n", map_data->width, i);
	if (!map_data->error_flag
		&& map_data->bottom_flag && map_data->width != i)
		map_data->error_flag = 5;
	map_data->bottom_flag++;
}

static void	increase_pce_flags(char special_char, t_map *map_data)
{
	if (special_char == 'P')
	{
		map_data->p_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = 2;
	}
	if (special_char == 'C')
	{
		map_data->c_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = 4;
	}
	if (special_char == 'E')
	{
		map_data->e_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = 3;
	}
}

static void	middle_line_check(char *line, t_map *map_data)
{
	int	i;
	int	map_line_len;
	
	i = 0;
	map_line_len = ft_strlen(line) - 1;
	if (map_line_len != map_data->width)
		map_data->error_flag = 5;
	if (!map_data->error_flag && line[0] == 1 && line[map_line_len] == 1)
		map_data->error_flag = 6;
	while (line[i] && !map_data->error_flag
		&& map_data->p_flag <= 1 && map_data->e_flag <= 1)
	{
		if (ft_strchr("PCE", line[i]))
		       	increase_pce_flags(line[i], map_data);
		else if (!ft_strchr("01\n", line[i]))
			map_data->error_flag = 7;
		i++;
	}
}

static int	map_is_correct(t_map *map_data)
{
	if (map_data->p_flag != 1)
		map_data->error_flag = 2;
	else if (map_data->e_flag != 1)
		map_data->error_flag = 3;
	else if (map_data->c_flag < 1)
		map_data->error_flag = 4;
	else if (map_data->width <= 2 || map_data->height <= 2
		|| (map_data->width * map_data->height) < 15)//Add max size
		map_data->error_flag = 5;
	else if (!map_data->error_flag)
		return (1);
	return (0);
}

void	read_and_check_map(char *map_pathname, t_map *map_data)
{
	int	check_fd;
	char	*current_line;

	current_line = "";
	check_fd = open(map_pathname, O_RDONLY);
	if (check_fd == -1)
		map_data->error_flag = 1;
	while (map_data->bottom_flag <= 1 && !map_data->error_flag)
	{
		current_line = get_next_line(check_fd);
		ft_printf("%s", current_line);//debug
		ft_printf("Width is %d\n", map_data->width);//debug
		if (!map_data->width || !ft_strrchr(current_line, '\n'))/*This
		is failing because final line soometimes have \n.
		So, check a new way to see if a line is the end*/
			top_bottom_check(current_line, map_data);
		else
			middle_line_check(current_line, map_data);
		free(current_line);
		map_data->height++;
	}
	ft_printf("p_flag is %d\n", map_data->error_flag);//debug
	if (map_data->error_flag || !map_is_correct(map_data))
		print_error(map_data);
	close(check_fd);
}
