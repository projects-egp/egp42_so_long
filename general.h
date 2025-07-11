/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:46:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/07/12 00:57:40 by enrgil-p         ###   ########.fr       */
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
int		open_map(char *map_pathname, t_map *map_data);
void	check_line_by_line(int fd, t_map *map_data, t_list **lines);
/*	*	manage_error	*	*/
void	print_error(t_map *map_data);
void	close_clean_and_exit_error(int fd, char *read_line,
			t_list **lines_list, t_map *data);
/*	*	parse_utils*	*/
int		check_width(char *line, t_map *data);
void	add_new_line(char *read_line, t_list **lines_list, t_map *data);
/*	*	manage_window	*	*/
int		create_window(t_map *map_data, t_mlx *mlx_data);
void	print_map(t_map *map_data, t_mlx *mlx_data);
int		key_press(int key, t_mlx *mlx);

#endif
