/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:57:03 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:23 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	print_error(t_map *map_data)
{
//If it iss needed, change name to parse_error()
	if (map_data->map)
		free_strings_array(map_data->map);
	if (map_data->error_flag == 1)
		ft_putendl_error("Error\nWrong number of P position on map");
	if (map_data->error_flag == 2)
		ft_putendl_error("Error\nWrong number of Exit position on map");
	if (map_data->error_flag == 3)
		ft_putendl_error("Error\nNeeded at east one item C on the map");
	if (map_data->error_flag == 4)
		ft_putendl_error("Error\nWrong size of map");
	if (map_data->error_flag == 5)
		ft_putendl_error("Error\nMap must be surrounded by 1 chars");
	if (map_data->error_flag == 6)
		ft_putendl_error("Error\nChar forbidden. Allowed: 0 1 P C E");
	if (map_data->error_flag == 7)
		ft_putendl_error("Error\nFile empty");
	if (map_data->error_flag == 8)
		ft_putendl_error("Error\nMap invalid, can't reach all C and E");
	if (map_data->error_flag == 9)
		ft_putendl_error("Error\nMa invalid, can't reach all C and E");
	exit(EXIT_FAILURE);
}
