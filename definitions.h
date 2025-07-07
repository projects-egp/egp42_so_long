/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:28:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 16:54:21 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"

#define EXPECTED_FORMAT "maps/<name-of-map-file>.ber"

typedef	struct s_map
{
	char	**map;
	int	height;
	int	width;
	int	p_flag;
	int	c_flag;
	int	e_flag;
	int	error_flag;//I need to think better this one
}	t_map;

#endif
