/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:13:02 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 17:13:45 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	check_width(char *line, t_map *data)
{
	int	len;

	len = ft_strlen(line);
	if (ft_strrchr(line, '\n'))
		len -= 1;
	if (!data->width)
		data->width = len;
	else if (data->width != len)
		data->error_flag = 4;
	return (len);
}
