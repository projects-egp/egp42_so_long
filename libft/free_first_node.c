/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_first_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:47:13 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/09 13:17:22 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complete_libft.h"

void	free_first_node(t_list *list)
{
	t_list	*aux;
	
	aux = list;
	list = list->next;
	free(aux);
}
