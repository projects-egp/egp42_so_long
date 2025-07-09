/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 22:13:02 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 20:37:46 by enrgil-p         ###   ########.fr       */
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
	else if (data->width != len || data->width <= 2)
		data->error_flag = 4;
	return (len);
}

void	add_new_line(char *read_line, t_list **lines_list, t_map *data)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew(read_line);
	if (!new)
	{
		free_full_list(lines_list);
		data->error_flag = 9;
		return ;
	}
	ft_lstadd_front(lines_list, new);
}
