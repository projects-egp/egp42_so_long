/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:28:09 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/06 15:36:59 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int arg_counter, char **arg_vector)
{
	if (arg_counter != 2 && !map_format(arg_vector[1]))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putendl_error("Expected: ./so_long <Name-of-map-file>.ber");
	}
	//Parse
	//Create and manage window
}
