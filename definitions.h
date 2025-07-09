/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:28:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 18:18:51 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"

# define EXPECTED_FORMAT "maps/<name-of-map-file>.ber"
# define MIN_MAP_SIZE 15// == (3 * 5)
# define MAX_MAP_SIZE 3080// == (77 * 40)

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		*p_position[2];
	int		p_flag;
	int		c_flag;
	int		e_flag;
	int		error_flag;
}	t_map;

#endif
