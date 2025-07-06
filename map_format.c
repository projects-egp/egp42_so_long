/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:37:24 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/06 16:27:56 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	map_format(char *map_file, int *error_flag)
{
	char	*dot_position;

	if	(!ft_strnstr(map_file, ".ber", 4))
	{
		dot_position = ft_strchr(map_file, '.');
		if (dot_position && ft_strnstr(dot_position, ".ber", 4)
			&& dot_position[4] == '\0')
			return (1);
	}
	*error_flag = 1;
	return (0);
}
