/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:37:24 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 16:27:36 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	map_format(char *map_file)
{
	char	*dot_position;

	if (ft_strnstr(map_file, ".ber", 4))
		ft_putendl_error("Error\nGood format, but file has no name");
	else
	{
		dot_position = ft_strchr(map_file, '.');
		if (dot_position && ft_strnstr(dot_position, ".ber", 4)
			&& dot_position[4] == '\0')
			return ;
		ft_putstr_fd("Error\nWrong format. Expected: ", 2);
		ft_putendl_error(EXPECTED_FORMAT);
	}
	exit(EXIT_FAILURE);
}
