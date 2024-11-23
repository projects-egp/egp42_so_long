/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2024/11/23 21:16:28 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include <unistd.h>

#define WIN_SIZE_X	976
#define WIN_SIZE_Y	576

/*Remember bpp == bits_per_pixel*/
typedef	struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

void	*create_image(void *mlx_ptr);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
