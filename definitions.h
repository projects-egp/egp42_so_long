/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:28:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 12:17:36 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

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
