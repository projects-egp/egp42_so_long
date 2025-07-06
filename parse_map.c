/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:20:12 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/06 23:13:22 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	top_bottom_check(char *line, t_map *map_data);
{
	int		i;
	static	int	bottom_flag;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && !bottom_flag)
			map_data->width = i;
		else if (line[i] != '1' && line[i] != '\n')
			return (0);
		i++;
	}
	if (bottom_flag++ == 0)
		i -= 1;
	if (map_data->width != i)
		return (0);
	return (1);
}

static int	read_and_check_map(char *map_pathname, t_map *map_data)
{
	int	check_fd;
	char	*current_line;
	char	*checked_line;

	current_line = "";
	check_fd = open(map_pathname, O_RDONLY);
	if (check_fd == -1)
		/*Error message*/exit (EXIT_FAILURE);
	while (current_line != NULL)
	{
		if (!map_data->height || !ft_strrchr(current_line, '\n'))
			top_bottom_check(current_line, map_data);
		else
		{
			//(len = ft_strlen(current_line) - 1) == width;
			//if current_line[0] == 1 && current_line[len] == 1;
			//ft_strchr("01", current_line[i]);
			//if ft_strchr("PCE", current_line[i]), check ?_flag;
			//	if ?_flag == 0, ?_flag++; if == 1, exit;
		}
	}
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
