/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/06 21:39:29 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int arg_counter, char **arg_vector)
{
	int	error_flag;
	t_map	map;

	error_flag = 0;
	if (arg_counter == 2)
	{
		if (!map_format(arg_vector[1], &error_flag))
			/*Error message*/return (1);
		open_map(arg_vector[1], &map);
		//Parse
		//Create and manage window
		return (0);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putendl_error("Expected: ./so_long <Name-of-map-file>.ber");
	return (1);
}
