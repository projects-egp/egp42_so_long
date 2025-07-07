/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 16:24:22 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int arg_counter, char **arg_vector)
{
	t_map	map;

	if (arg_counter == 2)
	{
		map_format(arg_vector[1]);
		open_map(arg_vector[1], &map);
		//Parse
		//Create and manage window
		return (0);
	}
	ft_putstr_fd("Error\nExpected: ./so_long ", 2);
	ft_putendl_error(EXPECTED_FORMAT);
	return (1);
}
