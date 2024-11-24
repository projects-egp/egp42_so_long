/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:42:36 by enrgil-p          #+#    #+#             */
/*   Updated: 2024/11/24 01:05:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
//	t_data	img;
	unsigned int	color_red;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
	win_ptr = mlx_new_window(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, "Window");
//	img.img = mlx_new_image(mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
//		&img.line_length, &img.endian);
	color_red = 0xF9D34C;
	for (int x = 0; x < 500; x++)
		mlx_pixel_put(mlx_ptr, win_ptr, 0 + x, 0 + x, color_red);
//	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
//	mlx_destroy_window(mlx_ptr, win_ptr);
//	mlx_destroy_display(mlx_ptr);
//	free(mlx_ptr);
	return (0);
}
