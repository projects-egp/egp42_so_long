/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/10 15:08:57 by enrgil-p         ###   ########.fr       */
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

void	map_format(char *map_path);
int	open_map(char *map_pathname, t_map *map_data);
void	check_line_by_line(int fd, t_map *map_data, t_list **lines);
/*	*	manage_error	*	*/
void	print_error(t_map *map_data);
void	close_clean_and_exit_error(int fd, t_list **lines_list, t_map *data);
/*	*	check_line_utils*	*/
int	check_width(char *line, t_map *data);
void	add_new_line(char *read_line, t_list **lines_list, t_map *data);

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
