/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/10 19:33:51 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int arg_counter, char **arg_vector)
{
	t_map	map;

	if (arg_counter == 2)
	{
		map_format(arg_vector[1]);
		if (!open_map(arg_vector[1], &map))
		{
			ft_putstr_fd("Error\nFail trying to open ", 2);
			ft_putendl_error(arg_vector[1]);
			return (1);
		}
//		execute
		free_strings_array(map.map);
		//Create and manage window
		return (0);
	}
	ft_putstr_fd("Error\nExpected: ./so_long ", 2);
	ft_putendl_error(EXPECTED_FORMAT);
	return (1);
}
