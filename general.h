/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/07 16:37:09 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/complete_libft.h"
# include "definitions.h"

void	map_format(char *map_file);

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

#endif
