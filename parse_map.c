/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:20:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 13:11:12 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	top_bottom_check(char *line, t_map *map_data)
{
	int		i;
	static	int	bottom_flag;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && !bottom_flag)
			map_data->width = i;
		else if (line[i] != '1' && line[i] != '\n')
		{
			map_data->error_flag = /*something*/;
			return (0);
		}
		i++;
	}
	if (bottom_flag++ == 0)
		i -= 1;
	if (map_data->width != i)
	{
		map_data->error_flag = /*something*/;
		return (0);
	}
	return (1);
}

static void	increase_pce_flag(char special_char, t_map *map_data)
{
	if (special_char == 'P')
	{
		map_data->p_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = /*something*/;
	}
	if (special_char == 'C')
	{
		map_data->c_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = /*something*/;
	}
	if (special_char == 'E')
	{
		map_data->e_flag++;
		if (map_data->p_flag > 1)
			map_data->error_flag = /*something*/;
	}
}

static int	middle_line_check(char *line, t_map *map_data)
{
	int	i;
	int	map_line_len;
	
	i = 0;
	map_line_len = ft_strlen(line) - 1;
	if (map_line_len != map_data->width)
		map_data->error_flag = /*something*/;
	if (line[0] == 1 && line[map_line_len] == 1)
		map_data->error_flag = /*something*/;
	while (line[i] && !map_data->error_flag
		&& map_data->p_flag <= 1 && map_data->e_flag <= 1)
	{
		if (ft_strchr("PCE", line[i]))
		       	increase_pce_flag(line[i], map_data);
		else if (!ft_strchr("01", line[i]))
			map_data->error_flag = /*something*/;
		i++;
	}
	//Check if PCE are at least 1;
	return (1);/*How I know this is the problem for message???*/
}

static int	read_and_check_map(char *map_pathname, t_map *map_data)
{
	int	check_fd;
	int	chars_flag;
	char	*current_line;
	char	*checked_line;

	current_line = "";
	chars_flag = 1;
	check_fd = open(map_pathname, O_RDONLY);
	if (check_fd == -1)
		/*Error message*/exit (EXIT_FAILURE);
	while (current_line != NULL || chars_flag != 0)/*Change this to error_flag*/
	{
		if (!map_data->height || !ft_strrchr(current_line, '\n'))
			chars_flag = top_bottom_check(current_line, map_data);
		else
			chars_flag = middle_line_check(current_line, map_data);
		free(current_line);
		map_data->height++;
	}
	if (!chars_flag)
		/*Error message*/exit (EXIT_FAILURE);
	close(check_fd);
}

//Open map_pathname twice: once for check, next to flodfill and create window
void	open_map(char *map_pathname, t_map *map_data)
{
	int	fd_map;
	
	ft_bzero(map_data);
	if (!read_and_check_map(map_pathname, map_data))
	fd_map = open(map_pathname, O_RDONLY);
	if (fd_map == -1)
		/*Error message*/exit (EXIT_FAILURE);

}
